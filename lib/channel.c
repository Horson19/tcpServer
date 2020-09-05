//
// Created by HorsonChan on 2020/8/23.
//
#include "channel.h"
#include "common.h"
#include "event_loop.h"

struct channel *
channel_new(int fd, int events,
        event_read_callback eventReadCallback,
        event_write_callback eventWriteCallback,
        void *data) {
    struct channel *channel = malloc(sizeof(struct channel));
    channel->fd = fd;
    channel->events = events;
    channel->data = data;
    channel->eventReadCallback = eventReadCallback;
    channel->eventWriteCallback = eventWriteCallback;
    return channel;
}

int channel_write_event_is_enable(struct channel *channel) {
    return channel->events & EVENT_WRITE;
}

int channel_write_event_enable(struct channel *channel) {
    struct event_loop *eventLoop = (struct event_loop *)channel->data;
    channel->events = channel->events | EVENT_WRITE;
    event_loop_update_channel_event(eventLoop, channel->fd, channel);
}

int channel_write_event_disable(struct channel *channel) {
    struct event_loop *eventLoop = (struct event_loop *)channel->data;
    channel->events = channel->events | ~EVENT_WRITE;
    event_loop_update_channel_event(eventLoop, channel->fd, channel);
}