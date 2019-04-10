/*
** EPITECH PROJECT, 2019
** algo_maze.c
** File description:
** algorithme for perfect and imperfect maze
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static void make_imperfect_map(map_t *map, int y, int x)
{
    int r = 0;

    r = rand() % 3;
    map->map[y][x] = 'X';

    if (r == 1 && x < map->x - 1 && x > 2)
        map->map[y][x + 1] = 'X';
    else if (r == 0)
        map->map[y - 1][x] = 'X';
}

static void make_map(map_t *map, int y, int x, int opt)
{
    int r = 0;

    if (opt == 1)
        map->map[y][x] = 'X';
    if (opt == 3) {
        r = rand() % (map->y + map->x);
        ((r % 2) == 0) ? map->map[y][x] = 'X': 0;
    }
    if (opt == 4)
        ((x % 2) == 0) ? make_imperfect_map(map, y, x) : 0;
}

void btree(map_t *map, pos_t *pos, int c)
{

    for (int y = 0; y < map->y; ++y)
        for (int x = 0; x < map->x; ++x)
            map->map[y][x] = '*';
    for (int y = 0; y < map->y; ++y) {
        for (int x = 0; x < map->x; ++x) {
            (y == 0) ? make_map(map, y, x, 1) : 0;
            ((y % 2) == 0 && y != 0 && c == 0) ? make_map(map, y, x, 4) : 0;
            (y == pos->end_y) ? make_map(map, y, x, 3) : 0;
        }
    }
    map->map[0][0] = '*';
    map->map[1][0] = '*';
    map->map[pos->end_y][pos->end_x] = '*';
    map->map[pos->end_y - 1][pos->end_x] = '*';
    resolve_map(map);
}
