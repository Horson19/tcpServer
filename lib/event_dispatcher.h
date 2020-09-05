//
// Created by HorsonChan on 2020/8/23.
//

#ifndef SOCKET_FRAMEWORK_EVENT_DISPATCHER_H
#define SOCKET_FRAMEWORK_EVENT_DISPATCHER_H

#include "channel.h"

struct event_dispatcher {
    const char *name;

    void *(*init)(struct event_loop *eventLoop);
    int (*add) (struct event_loop *eventLoop, struct channel *channel);
    int (*del) (struct event_loop *eventLoop, struct channel *channel);
    int (*update) (struct event_loop *eventLoop, struct channel *channel);
    int (*dispatch) (struct event_loop *eventLoop, struct timeval *timeval);
    void (*clear) (struct event_loop *eventLoop);
};



#endif //SOCKET_FRAMEWORK_EVENT_DISPATCHER_H
