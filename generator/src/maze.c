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
    for (int y = 0; y < map->y; y++)
        for (int x = 0; x < map->x; x++)
            map->map[y][x] = 'x';
    map->map[end_y][end_x] = '*';
}

void maze_full(map_t *map)
{
    int end_y = map->y - 1;
    int end_x = map->x - 1;

    init_maze(map);
    map->map[0][0] = '*';
    putchar('\n');
}

void print_maze(map_t *map)
{
    for (int i = 0; i < map->y; i++)
        printf("%s\n", map->map[i]);
}

void maze_generator(map_t *map)
{
    maze_full(map);
    print_maze(map);
}
