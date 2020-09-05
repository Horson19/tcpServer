//
// Created by haocheng on 2020/9/1.
//
#include "buffer.h"
#include "common.h"

#define INIT_BUFFER_SIZE 65536
struct buffer *buffer_new() {
    struct buffer *buffer = malloc(sizeof(struct buffer));
    buffer->data = malloc(INIT_BUFFER_SIZE);
    buffer->total_size = INIT_BUFFER_SIZE;
    buffer->readIndex = 0;
    buffer->writeIndex = 0;
}

int buffer_writeable_size(struct buffer *buffer) {
    return buffer->total_size - buffer->writeIndex;
}

int buffer_readable_size(struct buffer *buffer) {
    return buffer->writeIndex - buffer->readIndex;
}

int buffer_front_spare_size(struct buffer *buffer) {
    return buffer->readIndex;
}

void make_room(struct buffer *buffer, int size) {
    if (buffer_writeable_size(buffer) >= size) {
        return;
    }
    if (buffer_front_spare_size(buffer) + buffer_writeable_size(buffer) >= size) {
        int readable = buffer_readable_size(buffer);
        for (int i = 0; i < readable; ++i) {
            memcpy(buffer->data + i, buffer->data + buffer->readIndex + i, 1);
        }
        buffer->readIndex = 0;
        buffer->writeIndex = readable;
    } else {
        void *tmp = realloc(buffer->data, buffer->total_size + size);
        if (tmp == NULL) {
            return;
        }
        buffer->data = tmp;
        buffer->total_size += size;
    }
}

int buffer_append(struct buffer *buffer, void *data, int size) {
    if (data != NULL) {
        make_room(buffer, size);
        memcpy(buffer->data + buffer->writeIndex, data, size);
        buffer->writeIndex += size;
    }
}

int buffer_socket_read(struct buffer *buffer, int fd) {
    char additional_buffer[INIT_BUFFER_SIZE];
    bzero(additional_buffer, INIT_BUFFER_SIZE);
    struct iovec vec[2];
    int max_writeable = buffer_writeable_size(buffer);
    vec[0].iov_base = buffer->data + buffer->writeIndex;
    vec[0].iov_len = max_writeable;
    vec[1].iov_base = buffer;
    vec[1].iov_len = sizeof(additional_buffer);
    int res = readv(fd, &vec, 2);
    if (res <= 0) {
        return -1;
    } else if (res <= max_writeable) {
        buffer->writeIndex += res;
    } else {
        buffer->writeIndex = buffer->total_size;
        buffer_append(buffer, additional_buffer, res - max_writeable);
    }
}
