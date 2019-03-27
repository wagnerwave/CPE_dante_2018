/*
** EPITECH PROJECT, 2019
** maze algorithme
** File description:
** maze
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int new_rand(map_t *map)
{
    int i = rand() + map->y;
    int j = rand() * map->x;

    return (((rand() * (i + j)) % 2) ? 1 : 0);
}

int move_up(map_t *map, int x, int y)
{
    map->map[y - 1][x] = '*';
    return (y - 1);
}

int move_left(map_t *map, int x, int y)
{
    map->map[y][x - 1] = '*';
    return (x - 1);
}

void maze(map_t *map, pos_t *pos)
{
    int a = 0;
    int e_x = pos->end_x;
    int e_y = pos->end_y;

    while (e_x > 0 && e_y > 0) {
        a = new_rand(map);
        if (a == 1 && e_x != 0) {
            e_y = move_up(map, e_x, e_y);
        } else {
            e_x = move_left(map, e_x, e_y);
        }
    }
}