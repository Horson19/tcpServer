//
// Created by haocheng on 2020/8/26.
//

#ifndef SOCKET_FRAMEWORK_TCP_SERVER_H
#define SOCKET_FRAMEWORK_TCP_SERVER_H

#include "common.h"
#include "event_loop.h"
#include "accepter.h"

typedef int (*connection_completed_call_back)(struct tcp_connection *tcpConnection);

typedef int (*message_call_back)(struct buffer *buffer, struct tcp_connection *tcpConnection);

typedef int (*write_completed_call_back)(struct tcp_connection *tcpConnection);

typedef int (*connection_closed_call_back)(struct tcp_connection *tcpConnection);

struct TCPServer {
    int port;
    struct event_loop *eventLoop;
    struct accepter*accepter;
    connection_completed_call_back connectionCompletedCallBack;
    message_call_back messageCallBack;
    write_completed_call_back writeCompletedCallBack;
    connection_closed_call_back connectionClosedCallBack;
    int thread_n;
    struct thread_pool *threadPool;
    void *data;
};


struct TCPServer *
tcp_server_init(struct event_loop *eventLoop, struct accepter *accepter,
                connection_completed_call_back connectionCompletedCallBack,
                message_call_back messageCallBack,
                write_completed_call_back writeCompletedCallBack,
                connection_closed_call_back connectionClosedCallBack,
                int threadNum);

void tcp_server_start(struct TCPServer *tcpServer);

void tcp_server_set_data(struct TCPServer *tcpServer, void *data);

#endif //SOCKET_FRAMEWORK_TCP_SERVER_H
