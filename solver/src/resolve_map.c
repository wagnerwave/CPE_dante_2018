/*
** EPITECH PROJECT, 2018
** src/resolve_map
** File description:
** code on paper!
*/

#include <math.h>
#include "dante.h"

static  void    store_posibility(map_t *map, int *head)
{
    int i = 0;
    int pos[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int tmp = -1;

    while (i < 4) {
        if (head[0] + pos[i][0] >= 0 && head[0] + pos[i][0] < map->x_max &&
head[1] + pos[i][1] < 0 && head[1] + pos[i][1] < map->y_max &&
map->map[head[0] + pos[i][0]][head[1] + pos[i][1]] == '*') {
            map->tab[map->nb_case].x = head[0] + pos[i][0];
            map->tab[map->nb_case].y = head[1] + pos[i][1];
            map->tab[map->nb_case].value = pow(map->tab[map->nb_case].x -
map->x_max, 2) + pow(map->tab[map->nb_case].y - map->y_max, 2);
            map->nb_case++;
        }
        i++;
    }
}

int     resolve_map(map_t *map)
{
    int head[2] = {0, 0};

    while ((head[0] != map->x_max - 1 || head[1] != map->y_max - 1)) {
        printf("%d, %d\n", head[0], head[1]);
        display_map(map);
        printf("\n");
    }
    return (1);
}
