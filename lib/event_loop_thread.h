//
// Created by haocheng on 2020/8/26.
//

#ifndef SOCKET_FRAMEWORK_EVENT_LOOP_THREAD_H
#define SOCKET_FRAMEWORK_EVENT_LOOP_THREAD_H

#include <pthread.h>

struct event_loop_thread {
    struct event_loop *eventLoop;
    pthread_t thread_tid;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    char *thread_name;
    long thread_count; //connections handled
};

int event_loop_thread_init(struct event_loop_thread *eventLoopThread, int);

//由主线程调用，初始化一个子线程，并且让子线程开始运行event_loop
struct event_loop *event_loop_thread_start(struct event_loop_thread *eventLoopThread);

#endif //SOCKET_FRAMEWORK_EVENT_LOOP_THREAD_H
