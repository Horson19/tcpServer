//
// Created by HorsonChan on 2020/8/23.
//

#ifndef SOCKET_FRAMEWORK_EVENT_LOOP_H
#define SOCKET_FRAMEWORK_EVENT_LOOP_H

#include "channel.h"
#include "channel_map.h"
#include "event_dispatcher.h"
#include <pthread.h>

extern const struct event_dispatcher poll_dispatcher;

struct channel_element {
    int type;
    struct channel *channel;
    struct channel_element *next;
};

struct event_loop {
    int quit;
    const struct event_dispatcher *eventDispatcher;

    void *event_dispatcher_data;
    struct channel_map *channelMap;

    int is_handle_pending;
    struct channel_element *pending_head;
    struct channel_element *pending_tail;

    pthread_t owner_thread_id;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int socketPair[2];
    char *thread_name;
};

struct event_loop *event_loop_init();

struct event_loop *event_loop_init_with_name(char *thread_name);

int event_loop_run(struct event_loop *eventLoop);

int channel_event_activate(struct event_loop *eventLoop, int fd, int events);

int event_loop_add_channel_event(struct event_loop *eventLoop, int fd, struct channel *channel1);

int event_loop_remove_channel_event(struct event_loop *eventLoop, int fd, struct channel *channel1);

int event_loop_update_channel_event(struct event_loop *eventLoop, int fd, struct channel *channel1);


#endif //SOCKET_FRAMEWORK_EVENT_LOOP_H
