//
// Created by HorsonChan on 2020/8/23.
//

#ifndef SOCKET_FRAMEWORK_CHANNEL_H
#define SOCKET_FRAMEWORK_CHANNEL_H

#define EVENT_READ 0x02
#define EVENT_WRITE 0x04
#define EVENT_SIGNAL 0x08

typedef int (*event_read_callback)(void *data);
typedef int (*event_write_callback)(void *data);

struct channel {
    int fd;
    int events;

    event_read_callback eventReadCallback;
    event_write_callback eventWriteCallback;
    void *data;
};

struct channel *channel_new(int fd, int events, event_read_callback eventReadCallback, event_write_callback eventWriteCallback, void *data);

int channel_write_event_is_enable(struct channel *channel);

int channel_write_event_enable(struct channel *channel);

int channel_write_event_disable(struct channel *channel);


#endif //SOCKET_FRAMEWORK_CHANNEL_H
