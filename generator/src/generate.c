/*
** EPITECH PROJECT, 2018
** src/generate
** File description:
** example of bad code:
*/

#include "my.h"

void    put_back_star(map_t *map, size_t y, size_t x)
{
    size_t tmp;

    if (x == 0 || y == 0) {
        if (x > 0)
            map->map[y][x - 1] = '*';
        if (y > 0)
            map->map[y - 1][x] = '*';
        return ;
    }
    tmp = rand() % 2;
    if (tmp == 0)
        map->map[y][x - 1] = '*';
    else
        map->map[y - 1][x] = '*';
}

void    generate(map_t *map)
{
    size_t i = 0;
    size_t j;

    while (i < (size_t)map->y) {
        j = 0;
        while (j < (size_t)map->x) {
            map->map[i][j] = '*';
            put_back_star(map, i, j);
            j += 2;
        }
        i += 2;
    }
    if (map->y % 2 == 0 && map->map[map->y - 2][map->x - 1] == 'X')
        map->map[map->y - 1][map->x - 2] = '*';
    map->map[map->y - 1][map->x - 1] = '*';
}

void    break_wall_imp(map_t *map)
{
    size_t i = 0;
    size_t j;

    while (i < (size_t)map->y) {
        j = 0;
        while (j < (size_t)map->x) {
            (!(rand() % 8)) ? map->map[i][j] = '*' : 0;
            j++;
        }
        i += 2;
    }
}
