/*
1;4804;0c** EPITECH PROJECT, 2019
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

static void make_perfect_map(map_t *map, int y, int x)
{
    int r = 0;

        r = rand() % 3;
        map->map[y][x] = 'X';

        if (r == 1 && x < map->x - 1 && x > 2)
            map->map[y][x + 1] = 'X';
        else if (r == 0)
            map->map[y - 1][x] = 'X';
        else if (r == 2) {
            map->map[y - 1][x] = 'X';
            map->map[y][x + 1] = 'X';
        }
}

static void make_map(map_t *map, int y, int x, int opt)
{
    int r = 0;

    if (opt == 1)
        map->map[y][x] = 'X';
    if (opt == 2)
        ((x % 2) == 0) ? make_perfect_map(map, y, x) : 0;
    if (opt == 3) {
        r = rand() % (map->y + map->x);
        ((r % 2) == 0) ? map->map[y][x] = 'X': 0;
    }
    if (opt == 4)
        ((x % 2) == 0) ? make_imperfect_map(map, y, x) : 0;
}


static void make_way(map_t *map, pos_t *pos)
{
    int y = 0;
    int x = 0;
    int r = 0;
    int i = 0;

    while (y != pos->end_y && x != pos->end_x && i < map->y) {
        r = rand() % 2;
        for (; map->map[y + 1][x] == '*' && y < pos->end_y - 1; y++)
        for (; map->map[y][x + 1] == '*' && x < pos->end_x - 1; x++)
        if (map->map[y + 1][x] == 'X' && map->map[y][x + 1] == 'X') {
            ((r % 2)) ? map->map[y + 1][x] = '*', y++ : 0;
            (!(r % 2)) ? map->map[y][x + 1] = '*', x++ : 0;
        }
        i++;
    }
    if (y != pos->end_y)
        for (int a = y; a < pos->end_y; a++, y++)
            map->map[y][x] = '*';
    if (x != pos->end_x)
        for (int b = x; b < pos->end_x; b++, x++)
            map->map[y][x] = '*';
}

void btree(map_t *map, pos_t *pos, int c)
{
    for (int y = 0; y < map->y; ++y)
        for (int x = 0; x < map->x; ++x)
            map->map[y][x] = '*';
    for (int y = 0; y < map->y; ++y) {
        for (int x = 0; x < map->x; ++x) {
            (y == 0) ? make_map(map, y, x, 1) : 0;
            ((y % 2) == 0 && y != 0 && c == 1) ? make_map(map, y, x, 2) : 0;
            ((y % 2) == 0 && y != 0 && c == 0) ? make_map(map, y, x, 4) : 0;
            (y == pos->end_y) ? make_map(map, y, x, 3) : 0;
        }
    }
    map->map[0][0] = '*';
    map->map[1][0] = '*';
    map->map[pos->end_y][pos->end_x] = '*';
    map->map[pos->end_y - 1][pos->end_x] = '*';
    make_way(map, pos);
}
