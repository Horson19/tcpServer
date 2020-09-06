//
// Created by haocheng on 2020/8/26.
//

#include "accepter.h"

struct accepter *accepter_init(int port) {
    struct accepter *accepter = malloc(sizeof(struct accepter));
    accepter->listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    accepter->listen_port = port;

    fcntl(accepter->listen_fd, F_SETFL, O_NONBLOCK);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int on = 1;
    setsockopt(accepter->listen_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    int rc = bind(accepter->listen_fd, (const struct sockaddr_in *)&addr, (socklen_t)sizeof(addr));
    if (rc < 0) {
        printf("bind socket failed: %s\n", strerror(errno));
    }

    rc = listen(accepter->listen_fd, 1024);

    if (rc < 0) {
        printf("listen failed: %s\n", strerror(errno));
    }

    signal(SIGPIPE, SIG_IGN);

    return accepter;

}
