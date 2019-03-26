/*
** EPITECH PROJECT, 2019
** maze.c
** File description:
** maze generator
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char choise(map_t *map)
{
    return ( (rand() * (map->y + map->x) % 2) == 1 ? '*' : 'X');
}

void init_maze(map_t *map)
{
    int end_y = map->y - 1;
    int end_x = map->x - 1;

    for (int y = 0; y < map->y; y++)
        for (int x = 0; x < map->x; x++)
            map->map[y][x] = choise(map);
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
    init_maze(map);
    print_maze(map);
}
