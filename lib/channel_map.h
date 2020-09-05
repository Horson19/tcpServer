//
// Created by HorsonChan on 2020/8/24.
//

#ifndef SOCKET_FRAMEWORK_CHANNEL_MAP_H
#define SOCKET_FRAMEWORK_CHANNEL_MAP_H

struct channel_map {
    void **entries;
    int n_entries;
};

int map_make_space(struct channel_map *map, int slot, int msize);

int map_init(struct channel_map *map);

int map_clear(struct channel_map *map);

#endif //SOCKET_FRAMEWORK_CHANNEL_MAP_H
