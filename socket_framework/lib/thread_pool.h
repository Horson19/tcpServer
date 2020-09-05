//
// Created by haocheng on 2020/8/26.
//

#ifndef SOCKET_FRAMEWORK_THREAD_POOL_H
#define SOCKET_FRAMEWORK_THREAD_POOL_H

#include "event_loop.h"
#include "event_loop_thread.h"

struct thread_pool {
    struct event_loop *mainLoop;
    int started;
    int thread_number;
    struct event_loop_thread *eventLoopThread;
    int position;//decide which thread should be choose
};

struct thread_pool *thread_pool_new(struct event_loop *mainLoop, int thread_n);

void thread_pool_start(struct thread_pool *);

struct event_loop *thread_pool_get_loop(struct thread_pool *);

int isInSameThread(struct event_loop *eventLoop);

#endif //SOCKET_FRAMEWORK_THREAD_POOL_H
