//
// Created by haocheng on 2020/8/26.
//

#include <assert.h>
#include "event_loop_thread.h"
#include "event_loop.h"
#include "common.h"

void *event_loop_thread_run(void *arg) {
    struct event_loop_thread *eventLoopThread = (struct event_loop_thread *)arg;
    pthread_mutex_lock(&eventLoopThread->mutex);

    eventLoopThread->eventLoop = event_loop_init_with_name(eventLoopThread->thread_name);
    printf("event loop thread init and signal, %s\n", eventLoopThread->thread_name);
    pthread_cond_signal(&eventLoopThread->cond);

    pthread_mutex_unlock(&eventLoopThread->mutex);

    event_loop_run(eventLoopThread->eventLoop);

}

int event_loop_thread_init(struct event_loop_thread *eventLoopThread, int i) {
    pthread_mutex_init(&eventLoopThread->mutex, NULL);
    pthread_cond_init(&eventLoopThread->cond, NULL);
    eventLoopThread->eventLoop = NULL;
    eventLoopThread->thread_tid = 0;
    char *buf = malloc(16);
    sprintf(buf, "thread - %d\0", i + 1);
    eventLoopThread->thread_name = buf;

    return 0;
}

struct event_loop *event_loop_thread_start(struct event_loop_thread *eventLoopThread) {
    pthread_create(&eventLoopThread->thread_tid, NULL, &event_loop_thread_run, eventLoopThread);
    assert(pthread_mutex_lock(&eventLoopThread->mutex) == 0);
    while (eventLoopThread->eventLoop == NULL)
        assert(pthread_cond_wait(&eventLoopThread->cond, &eventLoopThread->mutex) == 0);

    assert(pthread_mutex_unlock(&eventLoopThread->mutex) == 0);

    printf("event loop thread started name: %s\n", eventLoopThread->thread_name);
    return eventLoopThread->eventLoop;
}

