//
// Created by haocheng on 2020/8/26.
//

#include "thread_pool.h"
#include "common.h"
//1： same thread: 0： not the same thread
int isInSameThread(struct event_loop *eventLoop){
    return eventLoop->owner_thread_id == pthread_self();
}

struct thread_pool *thread_pool_new(struct event_loop *mainLoop, int thread_n) {
    struct thread_pool *threadPool = malloc(sizeof(struct thread_pool));
    threadPool->mainLoop = mainLoop;
    threadPool->position = 0;
    threadPool->started = 0;
    threadPool->thread_number = thread_n;
    threadPool->eventLoopThread = NULL;

    return threadPool;
}

void thread_pool_start(struct thread_pool *threadPool) {
    assert(!threadPool->started);
    assert(isInSameThread(threadPool->mainLoop));

    threadPool->started = 1;
    if (threadPool->thread_number <= 0)
        return;

    threadPool->eventLoopThread = malloc(threadPool->thread_number * (sizeof(struct event_loop_thread)));
    for (int i = 0; i < threadPool->thread_number; ++i) {
        event_loop_thread_init(&threadPool->eventLoopThread[i], i);
        event_loop_thread_start(&threadPool->eventLoopThread[i]);
    }
}

struct event_loop *thread_pool_get_loop(struct thread_pool *threadPool) {
    assert(threadPool->started);
    assert(isInSameThread(threadPool->mainLoop));

    struct event_loop *eventLoop = threadPool->mainLoop;
    if (threadPool->thread_number > 0) {
        eventLoop = threadPool->eventLoopThread[threadPool->position].eventLoop;
        if (++threadPool->position > threadPool->thread_number)
            threadPool->position = 0;
    }

    return eventLoop;
}
