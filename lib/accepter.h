//
// Created by haocheng on 2020/8/26.
//

#ifndef SOCKET_FRAMEWORK_ACCEPTER_H
#define SOCKET_FRAMEWORK_ACCEPTER_H

#include "common.h"

struct accepter {
    int listen_port;
    int listen_fd;
};

struct accepter *accepter_init(int port);

#endif //SOCKET_FRAMEWORK_ACCEPTER_H
