/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** initialisation of structure
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void init_map(map_t *map, char **av)
{
    map->error = 0;
    map->y = atoi(av[2]);
    map->x = atoi(av[1]);
    if (map->y == 0 || map->x == 0)
        map->error = 84;
    map->map = malloc(sizeof(char *) * (map->y + 1));
    for (int i = 0; i < map->y; i++)
        map->map[i] = malloc(sizeof(char **) * (map->x + 1));
}

int verif_init(map_t *map)
{
    if (map->error == 84) {
        if (map->y == 0) {
            dprintf(2, "Error: Y arguments is 0...\n");
            return 84;
        }
        if (map->x == 0) {
            dprintf(2, "Error: Y arguments is 0...\n");
            return 84;
        }
    }
    if (map->map == NULL) {
        dprintf(2, "Error: Map Malloc error...\n");
        return 84;
    }
    return 0;
}

void print_init(map_t *map)
{
    printf("error = [%d]\n", map->error);
    printf("y = [%d]\n", map->y);
    printf("x = [%d]\n", map->x);
}
