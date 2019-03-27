/*
** EPITECH PROJECT, 2019
** maze.c
** File description:
** maze generator
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void init_maze(map_t *map)
{
    int end_y = map->y - 1;
    int end_x = map->x - 1;

    for (int y = 0; y < map->y; y++)
        for (int x = 0; x < map->x; x++) {
            if (y == 0 && x < map->x - 1) {
                map->map[y][x] = '*';
            } else {
                ((x % 2) == 0) ? map->map[y][x] = '*' : 0;
                ((x % 2) == 1) ? map->map[y][x] = 'X' : 0;
            }
        }
    map->map[0][0] = '*';
    map->map[end_y][end_x] = '*';
}

void print_maze(map_t *map)
{
    for (int i = 0; i < map->y; i++)
        printf("%s\n", map->map[i]);
}

void maze_generator(map_t *map)
{
    pos_t *pos = malloc(sizeof(pos_t) + 1);

    if (pos == NULL)
        exit(84);
    init_pos(map, pos);
    init_maze(map);
    maze(map, pos);
    print_maze(map);
}
