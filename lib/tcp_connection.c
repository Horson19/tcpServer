//
// Created by haocheng on 2020/9/1.
//

#include "tcp_connection.h"
#include "common.h"
#include "thread_pool.h"

int handle_connection_closed(struct tcp_connection *tcpConnection) {
    struct event_loop *eventLoop = tcpConnection->eventLoop;
    struct channel *channel = tcpConnection->channel;
    event_loop_remove_channel_event(eventLoop, channel->fd, channel);
    if (tcpConnection->connectionClosedCallBack != NULL) {
        tcpConnection->connectionClosedCallBack(tcpConnection);
    }
}

int handle_read(void *data) {
    struct tcp_connection *tcpConnection = (struct tcp_connection *)data;
    struct buffer *input_buffer = tcpConnection->input_buffer;
    struct channel *channel = tcpConnection->channel;
    if (buffer_socket_read(input_buffer, channel->fd) > 0) {
        if (tcpConnection->messageCallBack != NULL) {
            tcpConnection->messageCallBack(input_buffer, tcpConnection);
        }
    } else {
        handle_connection_closed(tcpConnection);
    }
}

int handle_write(void  *data) {
    struct tcp_connection *tcpConnection = (struct tcp_connection *)data;
    struct buffer *output_buffer = tcpConnection->output_buffer;
    struct channel *channel = tcpConnection->channel;
    struct event_loop *eventLoop = tcpConnection->eventLoop;
    isInSameThread(eventLoop);
    ssize_t n = write(channel->fd, output_buffer->data + output_buffer->writeIndex, buffer_readable_size(output_buffer));
    if (n > 0) {
        output_buffer->readIndex += n;
        if (buffer_readable_size(output_buffer) == 0) {
            channel_write_event_disable(channel);
        }

        if (tcpConnection->writeCompletedCallBack != NULL) {
            tcpConnection->writeCompletedCallBack(tcpConnection);
        }
    } else {
        printf("handle write for tcp connection %s\n", tcpConnection->name);
    }
}

struct tcp_connection *
tcp_connection_new(int fd, struct event_loop *eventLoop,
                   connection_completed_call_back connectionCompletedCallBack,
                   connection_closed_call_back connectionClosedCallBack,
                   message_call_back messageCallBack,
                   write_completed_call_back writeCompletedCallBack) {
    struct tcp_connection *tcpConnection = malloc(sizeof(struct tcp_connection));
    tcpConnection->eventLoop = eventLoop;
    tcpConnection->connectionClosedCallBack = connectionClosedCallBack;
    tcpConnection->writeCompletedCallBack = writeCompletedCallBack;
    tcpConnection->messageCallBack = messageCallBack;
    tcpConnection->connectionCompletedCallBack = connectionCompletedCallBack;
    tcpConnection->input_buffer = buffer_new();
    tcpConnection->output_buffer = buffer_new();

    char *buffer = malloc(16);
    sprintf(buffer, "connection-%d\0", fd);
    tcpConnection->name = buffer;

    struct channel *channel = channel_new(fd, EVENT_READ, handle_read, handle_write, tcpConnection);
    tcpConnection->channel = channel;

    if (tcpConnection->connectionCompletedCallBack != NULL) {
        tcpConnection->connectionCompletedCallBack(tcpConnection);
    }

    event_loop_add_channel_event(eventLoop, fd, channel);

    return tcpConnection;
}


int tcp_connection_send_data(struct tcp_connection *tcpConnection, void *data, int size) {
    size_t nwrited = 0;
    size_t nleft = size;
    int fault = 0;
    struct channel *channel = tcpConnection->channel;
    struct buffer *buffer = tcpConnection->output_buffer;

    if (!channel_write_event_is_enable(channel) && buffer_readable_size(buffer) == 0) {
        nwrited = write(channel->fd, data, size);
        if (nwrited > 0) {
            nleft -= nwrited;
        } else {
            nwrited = 0;
            if (errno != EWOULDBLOCK) {
                if (errno == EPIPE || errno == ECONNRESET) {
                    fault = 1;
                }
            }
        }
    }

    if (!fault && nleft > 0) {
        buffer_append(buffer, data + nwrited, nleft);
        if (!channel_write_event_is_enable(channel)){
            channel_write_event_enable(channel);
        }
    }
    return nwrited;
}

int tcp_connection_send_buffer(struct tcp_connection *tcpConnection, struct buffer *buffer) {
    int size = buffer_readable_size(buffer);
    int result = tcp_connection_send_data(tcpConnection, buffer->data, buffer_readable_size(buffer));
    buffer->readIndex += size;
    return result;
}

void tcp_connection_shutdown(struct tcp_connection *tcpConnection) {
    if (shutdown(tcpConnection->channel->fd, SHUT_WR) < 0) {
        printf("tcp_connection_shutdown failed, socket: %d\n",tcpConnection->channel->fd);
    }
}