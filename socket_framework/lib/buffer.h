//
// Created by haocheng on 2020/9/1.
//

#ifndef SOCKET_FRAMEWORK_BUFFER_H
#define SOCKET_FRAMEWORK_BUFFER_H

struct buffer {
    char *data;
    int readIndex;
    int writeIndex;
    int total_size;
};

struct buffer *buffer_new();
int buffer_socket_read(struct buffer *buffer, int fd);
int buffer_readable_size(struct buffer *buffer);
int buffer_append(struct buffer *buffer, void *data, int size);

#endif //SOCKET_FRAMEWORK_BUFFER_H
