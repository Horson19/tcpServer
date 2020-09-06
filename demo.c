#include "lib/event_loop.h"
#include "lib/tcp_server.h"
#include "lib/common.h"
#include "lib/buffer.h"
#include "lib/tcp_connection.h"

int onConnectionCompleted(struct tcp_connection *tcpConnection) {
    printf("connection completed\n");
    return 0;
}

int onMessage(struct buffer *input, struct tcp_connection *tcpConnection) {
    printf("get message from tcp connection %s\n", tcpConnection->name);
    printf("%s", input->data);

    struct buffer *output = buffer_new();
    int size = buffer_readable_size(input);
    tcp_connection_send_buffer(tcpConnection, output);
    return 0;
}

int onWriteCompleted(struct tcp_connection *tcpConnection) {
    printf("write completed\n");
    return 0;
}

int onConnectionClosed(struct tcp_connection *tcpConnection) {
    printf("connection closed\n");
    return 0;
}

int main() {
    struct event_loop *eventLoop = event_loop_init();
    struct accepter *accepter = accepter_init(2020);
    struct TCPServer *tcpServer = tcp_server_init(eventLoop, accepter,
                                                  onConnectionCompleted, onMessage,
                                                  onWriteCompleted,
                                                  onConnectionClosed, 0);
    tcp_server_start(tcpServer);
    event_loop_run(eventLoop);
    return 0;
}
