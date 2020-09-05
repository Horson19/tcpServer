//
// Created by haocheng on 2020/8/26.
//

#include "common.h"
#include "tcp_server.h"
#include "thread_pool.h"
#include "tcp_connection.h"


struct TCPServer *
tcp_server_init(struct event_loop *eventLoop, struct accepter *accepter,
                connection_completed_call_back connectionCompletedCallBack,
                message_call_back messageCallBack,
                write_completed_call_back writeCompletedCallBack,
                connection_closed_call_back connectionClosedCallBack,
                int threadNum) {
    struct TCPServer *tcpServer = malloc(sizeof(struct TCPServer));
    tcpServer->eventLoop = eventLoop;
    tcpServer->threadPool = thread_pool_new(eventLoop, threadNum);
    tcpServer->thread_n = threadNum;
    tcpServer->writeCompletedCallBack = writeCompletedCallBack;
    tcpServer->messageCallBack = messageCallBack;
    tcpServer->connectionCompletedCallBack = connectionCompletedCallBack;
    tcpServer->connectionClosedCallBack = connectionClosedCallBack;
    tcpServer->accepter = accepter;
    tcpServer->data = NULL;

    return tcpServer;
}

int handle_connection_established(void *data) {
    struct TCPServer *tcpServer = (struct TCPServer *)data;
    struct accepter *accepter = tcpServer->accepter;
    int listenfd = accepter->listen_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int connectfd = accept(listenfd, (struct sockaddr *)&client_addr, (socklen_t)client_len);
    fcntl(connectfd, F_SETFL, O_NONBLOCK);
    printf("established connection fd: %d\n", connectfd);
    struct event_loop *eventLoop = thread_pool_get_loop(tcpServer->threadPool);
    struct tcp_connection *tcpConnection = tcp_connection_new(connectfd, eventLoop,
            tcpServer->connectionCompletedCallBack,
            tcpServer->connectionClosedCallBack,
            tcpServer->messageCallBack,
            tcpServer->writeCompletedCallBack);

    if (tcpServer->data != NULL) {
        tcpConnection->data = tcpServer->data;
    }
}

void tcp_server_start(struct TCPServer *tcpServer) {
    struct accepter *accepter = tcpServer->accepter;
    struct event_loop *eventLoop = tcpServer->eventLoop;
    thread_pool_start(tcpServer->threadPool);
    struct channel *channel = channel_new(accepter->listen_fd, EVENT_READ, handle_connection_established, NULL, tcpServer);
    event_loop_add_channel_event(eventLoop, accepter->listen_fd, channel);
    printf("tcp_server_did_started\n");
    return;
}