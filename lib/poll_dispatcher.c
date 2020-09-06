//
// Created by haocheng on 2020/8/25.
//

#include "event_loop.h"
#include "common.h"
#include <sys/poll.h>

#define INIT_POLL_DATA_SIZE 1024

struct poll_dispatcher_data {
    int event_count;
    int nfds;
    int realloc_copy;
    struct pollfd *event_set;
    struct pollfd *event_set_copy;
};

static void *poll_init(struct event_loop *eventLoop);
static int poll_add(struct event_loop *eventLoop, struct channel *channel);
static int poll_del(struct event_loop *eventLoop, struct channel *channel);
static int poll_update(struct event_loop *eventLoop, struct channel *channel);
static int poll_dispatch(struct event_loop *eventLoop, struct timeval *timeval);
static void poll_clear(struct event_loop *eventLoop);

const struct event_dispatcher poll_dispatcher = {
        "poll",
        poll_init,
        poll_add,
        poll_del,
        poll_update,
        poll_dispatch,
        poll_clear,
};

void *poll_init(struct event_loop *eventLoop) {
    struct poll_dispatcher_data *data = malloc(sizeof(struct poll_dispatcher_data));
    data->event_count = 0;
    data->nfds = 0;
    data->realloc_copy = 0;
    data->event_set = malloc(sizeof(struct pollfd) * INIT_POLL_DATA_SIZE);
    data->event_set_copy = 0;
    for (int i = 0; i < INIT_POLL_DATA_SIZE; i++)
        data->event_set[i].fd = -1;
    return data;
}

int poll_add(struct event_loop *eventLoop, struct channel *channel) {
    int fd = channel->fd;
    struct poll_dispatcher_data *data = eventLoop->event_dispatcher_data;
    int events = 0;
    if (channel->events & EVENT_READ) {
        events = events | POLLRDNORM;
    }

    if (channel->events & EVENT_WRITE) {
        events = events | POLLWRNORM;
    }


    int rc = -1;
    for (int i = 0; i < INIT_POLL_DATA_SIZE; ++i) {
        if (data->event_set[i].fd == -1) {
            data->event_set[i].fd = fd;
            data->event_set[i].events = events;
            rc = 0;
            break;
        }
    }

    printf("add fd: %d, status code: %d\n", fd, rc);

    return rc;
}

int poll_del(struct event_loop *eventLoop, struct channel *channel) {
    int rc = -1;
    int fd = channel->fd;
    if (fd >= INIT_POLL_DATA_SIZE) return rc;
    struct poll_dispatcher_data *data = eventLoop->event_dispatcher_data;

    for (int i = 0; i < INIT_POLL_DATA_SIZE; ++i) {
        if (data->event_set[i].fd == fd) {
            data->event_set[i].fd = -1;
            data->event_set[i].events = 0;
            rc = 0;
            break;
        }
    }

    printf("add fd: %d, status code: %d\n", fd, rc);

    return rc;
}

int poll_update(struct event_loop *eventLoop, struct channel *channel) {
    int rc = -1;
    int fd = channel->fd;
    if (fd >= INIT_POLL_DATA_SIZE) return rc;
    struct poll_dispatcher_data *data = eventLoop->event_dispatcher_data;

    int events = 0;
    if (channel->events & EVENT_READ) {
        events = events | POLLRDNORM;
    }

    if (channel->events & EVENT_WRITE) {
        events = events | POLLWRNORM;
    }

    for (int i = 0; i < INIT_POLL_DATA_SIZE; ++i) {
        if (data->event_set[i].fd == fd) {
            data->event_set[i].events = events;
            rc = 0;
            break;
        }
    }

    printf("add fd: %d, status code: %d\n", fd, rc);

    return rc;
}

int poll_dispatch(struct event_loop *eventLoop, struct timeval *timeval) {
    struct poll_dispatcher_data *data = eventLoop->event_dispatcher_data;
    int timewait = timeval->tv_sec * 1000 * 1000;
    int ready_num = poll(data->event_set, INIT_POLL_DATA_SIZE, timewait);
    if (ready_num < 0) {
        printf("poll error\n");
        exit(1);
    }
    if (ready_num == 0) {
        return 0;
    }

    for (int i = 0; i < INIT_POLL_DATA_SIZE; ++i) {
        int socket_fd;
        if ((socket_fd = data->event_set[i].fd) < 0)
            continue;

        if (data->event_set[i].revents > 0) {
            if (data->event_set[i].revents & POLLRDNORM) {
                channel_event_activate(eventLoop, socket_fd, EVENT_READ);
            }

            if (data->event_set[i].events & POLLWRNORM) {
                channel_event_activate(eventLoop, socket_fd, EVENT_WRITE);
            }
            if (--ready_num <= 0) break;
        }
    }

}
void poll_clear(struct event_loop *eventLoop) {
    struct poll_dispatcher_data *data = eventLoop->event_dispatcher_data;
    free(data->event_set);
    free(data->event_set_copy);
    data->event_set = NULL;
    data->event_set_copy = NULL;
    data->realloc_copy = 0;
    data->event_count = 0;
    data->nfds = 0;
    free(data);
    eventLoop->event_dispatcher_data = NULL;
}