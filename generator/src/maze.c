/*
** EPITECH PROJECT, 2019
** maze.c
** File description:
** maze generator
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void print_maze(map_t *map)
{
    int i = 0;

    while (i < map->y) {
        printf("%s", map->map[i]);
        if (i < map->y - 1)
            putchar('\n');
        i++;
    }
}

static void mem_maze(map_t *map)
{
    for (int y = 0; y < map->y; y++)
        memset(map->map[y], map->x, sizeof(char));
}

void maze_generator(map_t *map, int bool)
{
    pos_t *pos = malloc(sizeof(pos_t) + 1);

    if (pos == NULL)
        exit(84);
    init_pos(map, pos);
    mem_maze(map);
    if (bool == 0)
        btree(map, pos, 0);
    if (bool == 1)
        btree(map, pos, 1);
    print_maze(map);
}
