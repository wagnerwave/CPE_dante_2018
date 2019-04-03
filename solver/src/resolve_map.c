/*
** EPITECH PROJECT, 2018
** src/resolve_map
** File description:
** code on paper!
*/

#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "dante.h"

static  void    store_posibility(map_t *map, int *head)
{
    int i = 0;
    int pos[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    while (i < 4) {
        if (head[0] + pos[i][0] >= 0 && head[0] + pos[i][0] < map->x_max &&
head[1] + pos[i][1] >= 0 && head[1] + pos[i][1] < map->y_max &&
map->map[head[0] + pos[i][0]][head[1] + pos[i][1]] == '*') {
            map->tab[map->nb_case].used = 0;
            map->tab[map->nb_case].x = head[0] + pos[i][0];
            map->tab[map->nb_case].y = head[1] + pos[i][1];
            map->tab[map->nb_case].value = pow(map->x_max -
map->tab[map->nb_case].x, 2) + pow(map->y_max - map->tab[map->nb_case].y, 2);
            map->tab[map->nb_case].distance = head[2] + 1;
            map->map[map->tab[map->nb_case].x][map->tab[map->nb_case].y] = '.';
            map->nb_case++;
        }
        i++;
    }
}

static  int     chose_posibility(map_t *map, int *head)
{
    int     i = 0;
    size_t  tmp = UINT_MAX;
    int     choice = -1;

    while (i < map->nb_case) {
        if (map->tab[i].used == 0 && map->tab[i].value < tmp) {
            tmp = map->tab[i].value;
            choice = i;
        }
        i++;
    }
    if (choice == -1)
        return (0);
    map->tab[choice].used = 1;
    head[0] = map->tab[choice].x;
    head[1] = map->tab[choice].y;
    map->map[head[0]][head[1]] = 'u';
    head[2] = map->tab[choice].distance;
    map->itab[head[0]][head[1]] = map->tab[choice].distance;
    return (1);
}

static  int     to_start(map_t *map, int *head)
{
    int     i = 0;
    int     pos[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int     choice = -1;
    size_t  tmp = UINT_MAX;

    while (i < 4) {
        if (head[0] + pos[i][0] >= 0 && head[0] + pos[i][0] < map->x_max &&
head[1] + pos[i][1] >= 0 && head[1] + pos[i][1] < map->y_max &&
map->itab[head[0] + pos[i][0]][head[1] + pos[i][1]] != -1 &&
(size_t)(map->itab[head[0] + pos[i][0]][head[1] + pos[i][1]]) < tmp) {
            tmp = map->itab[head[0] + pos[i][0]][head[1] + pos[i][1]];
            choice = i;
        }
        i++;
    }
    if (choice == -1)
        return (0);
    head[0] += pos[choice][0];
    head[1] += pos[choice][1];
    map->map[head[0]][head[1]] = 'o';
    return (1);
}

static  void    final_map(map_t *map)
{
    int i = 0;
    int j;

    while (i < map->y_max) {
        j = 0;
        while (j < map->x_max) {
            (map->map[i][j] == '.' || map->map[i][j] == 'u') ?
map->map[i][j] = '*' : 0;
            j++;
        }
        i++;
    }
}

int     resolve_map(map_t *map)
{
    int head[3] = {0, 0, 0};

    while ((head[0] != map->x_max - 1 || head[1] != map->y_max - 1)) {
        if (!chose_posibility(map, head))
            return (0);
        store_posibility(map, head);
    }
    map->map[head[0]][head[1]] = 'o';
    while ((head[0] != 0 || head[1] != 0)) {
        if (!to_start(map, head))
            return (0);
    }
    final_map(map);
    return (1);
}
