//
// Created by HorsonChan on 2020/8/24.
//
#include "channel_map.h"
#include "common.h"

int map_init(struct channel_map *map) {
    map->entries = NULL;
    map->n_entries = 0;
}

int map_make_space(struct channel_map *map, int slot, int msize) {
    if (map->n_entries <= slot) {
        int nentries = map->n_entries ? map->n_entries : 32;
        void **tmp;

        while (nentries <= slot)
            nentries <<= 1;

        tmp = (void **) realloc(map->entries, nentries * msize);
        if (tmp == NULL)
            return (-1);

        memset(&tmp[map->n_entries], 0,
               (nentries - map->n_entries) * msize);

        map->n_entries = nentries;
        map->entries = tmp;
    }

    return (0);
}