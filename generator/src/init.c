/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** initialisation of structure
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void init_pos(map_t *map, pos_t *pos)
{
    pos->y = 0;
    pos->x = 0;
    pos->end_x = map->x - 1;
    pos->end_y = map->y - 1;
}

void init_map(map_t *map, error_t *err, char **av)
{
    err->error = 0;
    map->y = atoi(av[2]);
    map->x = atoi(av[1]);
    if (map->y == 0 || map->x == 0)
        err->error = 84;
    map->map = malloc(sizeof(char *) * (map->y + 1));
    for (int i = 0; i < map->y; i++) {
        map->map[i] = malloc(sizeof(char) * (map->x + 1));
        map->map[i][map->x] = '\0';
    }

}

int verif_init(map_t *map, error_t *err)
{
    if (err->error == 84) {
        if (map->y == 0) {
            dprintf(2, "Error: Y arguments is 0...\n");
            return 84;
        }
        if (map->x == 0) {
            dprintf(2, "Error: X arguments is 0...\n");
            return 84;
        }
    }
    if (map->map == NULL) {
        dprintf(2, "Error: Map Malloc error...\n");
        return 84;
    }
    return 0;
}
