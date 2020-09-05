//
// Created by HorsonChan on 2020/8/23.
//
#include "event_loop.h"
#include "common.h"

struct event_loop *event_loop_init() {
    return event_loop_init_with_name(NULL);
}
int event_loop_handle_pending_add(struct event_loop *eventLoop, int fd, struct channel *channel1) {
    printf("add channel fd: %d, thread: %s\n", fd, eventLoop->thread_name);
    struct channel_map *map = eventLoop->channelMap;

    if (fd < 0)
        return 0;

    if (fd > map->n_entries) {
        if (map_make_space(map, fd, sizeof(struct channel *)) == -1)
            return -1;
    }

    if (map->entries[fd] == NULL) {
        map->entries[fd] = channel1;
        eventLoop->eventDispatcher->add(eventLoop, channel1);
        return 1;
    }

    return 0;
}

int event_loop_handle_pending_remove(struct event_loop *eventLoop, int fd, struct channel *channel1) {
    printf("remove channel fd: %d, thread: %s\n", fd, eventLoop->thread_name);
    struct channel_map *map = eventLoop->channelMap;

    assert(fd == channel1->fd);

    if (fd < 0)
        return 0;

    if (fd > map->n_entries)
        return -1;

    struct channel *channel2 = map->entries[fd];
    int rc = eventLoop->eventDispatcher->del(eventLoop, channel2);

    map->entries[fd] = NULL;

    return rc;

}

int event_loop_handle_pending_update(struct event_loop *eventLoop, int fd, struct channel *channel1) {
    printf("update channel fd: %d, thread: %s\n", fd, eventLoop->thread_name);
    struct channel_map *map = eventLoop->channelMap;

    assert(fd == channel1->fd);

    if (fd < 0)
        return 0;

    if (fd > map->n_entries)
        return -1;

    struct channel *channel2 = map->entries[fd];
    int rc = eventLoop->eventDispatcher->update(eventLoop, channel2);

    return rc;
}

int event_loop_is_same_thread(struct event_loop *eventLoop) {
    return eventLoop->owner_thread_id == pthread_self();
}

int event_loop_handle_pending_channel(struct event_loop *eventLoop) {
    pthread_mutex_lock(&eventLoop->mutex);
    struct channel_element *channelElement = eventLoop->pending_head;
    eventLoop->is_handle_pending = 1;
    while (channelElement != NULL) {
        struct channel *channel1 = channelElement->channel;

        //map, and dispatcher action
        if (channelElement->type == 1) {
            event_loop_handle_pending_add(eventLoop, channel1->fd, channel1);
        } else if (channelElement->type == 2) {
            event_loop_handle_pending_remove(eventLoop, channel1->fd, channel1);
        } else if (channelElement->type == 3) {
            event_loop_handle_pending_update(eventLoop, channel1->fd, channel1);
        }
        channelElement = channelElement->next;
    }

    eventLoop->pending_head = eventLoop->pending_tail = NULL;
    eventLoop->is_handle_pending = 0;
    pthread_mutex_unlock(&eventLoop->mutex);
}

int event_loop_wake_up(struct event_loop *eventLoop) {
    char buf = 'a';
    ssize_t n = write(eventLoop->socketPair[0], &buf, sizeof buf);
    if (n != sizeof buf) {
        printf("wake up event loop write error\n");
    }
}

int handle_wake_up(void *data) {
    char c;
    struct event_loop *eventLoop = (struct event_loop *)data;
    int rc = read(eventLoop->socketPair[1], &c, sizeof(c));
    if (rc != sizeof c) {
        printf("wake up event loop read error\n");
    }
    printf("event loop did wake up: %s\n", eventLoop->thread_name);
}

void event_loop_channel_buffer_nolock(struct event_loop *eventLoop, int fd, struct channel *channel1, int type) {
    struct channel_element *channelElement = malloc(sizeof(struct channel_element));
    channelElement->channel = channel1;
    channelElement->type = type;
    channelElement->next = NULL;
    if (eventLoop->pending_head == NULL) {
        eventLoop->pending_head = eventLoop->pending_tail = channelElement;
    } else {
        eventLoop->pending_tail->next = channelElement;
        eventLoop->pending_tail = channelElement;
    }
}

int event_loop_do_channel_event(struct event_loop *eventLoop, int fd, struct channel *channel1, int type) {
    pthread_mutex_lock(&eventLoop->mutex);
    assert(eventLoop->is_handle_pending == 0);
    event_loop_channel_buffer_nolock(eventLoop, fd, channel1, type);
    pthread_mutex_unlock(&eventLoop->mutex);
    if (event_loop_is_same_thread(eventLoop)) {
        event_loop_handle_pending_channel(eventLoop);
    } else {
        event_loop_wake_up(eventLoop);
    }
    return 0;
}

int event_loop_add_channel_event(struct event_loop *eventLoop, int fd, struct channel *channel1) {
    return event_loop_do_channel_event(eventLoop, fd, channel1, 1);
}

int event_loop_remove_channel_event(struct event_loop *eventLoop, int fd, struct channel *channel1) {
    return event_loop_do_channel_event(eventLoop, fd, channel1, 2);
}

int event_loop_update_channel_event(struct event_loop *eventLoop, int fd, struct channel *channel1) {
    return event_loop_do_channel_event(eventLoop, fd, channel1, 3);
}

struct event_loop *event_loop_init_with_name(char *thread_name) {
    struct event_loop *eventLoop = malloc(sizeof(struct event_loop));
    pthread_mutex_init(&eventLoop->mutex, NULL);
    pthread_cond_init(&eventLoop->cond, NULL);

    if (thread_name != NULL) {
        eventLoop->thread_name = thread_name;
    } else {
        eventLoop->thread_name = "main thread";
    }

    eventLoop->quit = 0;
    eventLoop->channelMap = malloc(sizeof(struct channel_map));
    map_init(eventLoop->channelMap);

    eventLoop->eventDispatcher = &poll_dispatcher;
    eventLoop->event_dispatcher_data = eventLoop->eventDispatcher->init(eventLoop);

    eventLoop->owner_thread_id = pthread_self();

    if (socketpair(AF_LOCAL, SOCK_STREAM, 0, eventLoop->socketPair) < 0) {
        printf("create event loop socket pair failed\n");
    }

    eventLoop->pending_head = eventLoop->pending_tail = NULL;
    eventLoop->is_handle_pending = 0;

    struct channel *channel = channel_new(eventLoop->socketPair[0], EVENT_READ, handle_wake_up, NULL, eventLoop);
    event_loop_add_channel_event(eventLoop, eventLoop->socketPair[1], channel);

    return eventLoop;
}

int event_loop_run(struct event_loop *eventLoop) {
    assert(eventLoop != NULL);
    if (eventLoop->owner_thread_id != pthread_self()) {
        exit(1);
    }

    struct event_dispatcher *eventDispatcher = eventLoop->eventDispatcher;

    struct timeval tv;
    tv.tv_sec = 1;

    printf("event loop run: %s\n", eventLoop->thread_name);

    while (!eventLoop->quit) {
        eventDispatcher->dispatch(eventLoop, &tv);
        event_loop_handle_pending_channel(eventLoop);
    }

    printf("event loop finished: %s\n", eventLoop->thread_name);
}

int channel_event_activate(struct event_loop *eventLoop, int fd, int events) {
    struct channel_map *map = eventLoop->channelMap;

    if (fd < 0)
        return 0;

    if (fd >= map->n_entries)return (-1);

    struct channel *channel = map->entries[fd];

    assert(fd == channel->fd);

    if (events & EVENT_READ) {
        if (channel->eventReadCallback) channel->eventReadCallback(channel->data);
    }

    if (events & EVENT_WRITE) {
        if (channel->eventWriteCallback) channel->eventWriteCallback(channel->data);
    }

    return 0;

}
