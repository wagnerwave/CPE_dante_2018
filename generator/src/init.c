/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** initialisation of structure
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

void init_pos(map_t *map, pos_t *pos)
{
    pos->y = 0;
    pos->x = 0;
    pos->end_x = map->x - 1;
    pos->end_y = map->y - 1;
}

void init_map(map_t *map, error_t *err, char **av, int ac)
{
    err->error = 0;
    map->y = atoi(av[2]);
    map->x = atoi(av[1]);
    if (ac == 4 && !strcmp(av[3], "perfect") && map->y * map->x > 1000000)
        exit(84);
    if (map->y == 0 || map->x == 0)
        err->error = 84;
    map->map = malloc(sizeof(char *) * map->y);
    for (int i = 0; i < map->y; i++) {
        map->map[i] = malloc(sizeof(char) * (map->x + 1));
        map->map[i][map->x] = '\0';
    }
    for (int i = 0; i < map->y; i++)
        for (int x = 0; x < map->x; x++)
            map->map[i][x] = 'X';
    init_map_second(&map);
}

int verif_init(map_t *map, error_t *err)
{
    if (err->error == 84) {
        if (map->y == 0) {
            printf("Error: Y arguments is 0...");
            return 84;
        }
        if (map->x == 0) {
            printf("Error: X arguments is 0...");
            return 84;
        }
    }
    if (map->map == NULL) {
        printf("Error: Map Malloc error...");
        return 84;
    }
    return 0;
}
