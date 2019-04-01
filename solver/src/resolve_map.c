/*
** EPITECH PROJECT, 2018
** src/resolve_map
** File description:
** code on paper!
*/

#include <math.h>
#include "dante.h"

static  void    direction(map_t *map, int *head)
{
    int i = 0;
    int pos[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int tmp = -1;
    int choix = -1;

    while (i < 4) {
        if (head[1] + pos[i][1] >= 0 && head[1] + pos[i][1] < map->y_max &&
head[0] + pos[i][0] >= 0 && head[0] + pos[i][0] < map->x_max &&
map->map[head[0] + pos[i][0]][head[1] + pos[i][1]] == '*' && (tmp == -1 ||
pow((map->x_max) - (head[0] + pos[i][0]), 2) + pow((map->y_max) - (head[1] +
pos[i][1]), 2) < tmp)) {
            tmp = pow((map->x_max) - (head[0]), 2) +
pow((map->y_max) - (head[1]), 2);
            choix = i;
        }
        i++;
    }
    if (choix == -1)
        return ;
    if (map->tab[head[0] + pos[choix][0]][head[1] + pos[choix][1]] == -1 ||
map->tab[head[0]][head[1]] + 1 < map->tab[head[0] + pos[choix][0]][head[1] +
pos[choix][1]])
        map->tab[head[0] + pos[choix][0]][head[1] + pos[choix][1]] =
map->tab[head[0]][head[1]] + 1;
    head[0] += pos[choix][0];
    head[1] += pos[choix][1];
}

int     resolve_map(map_t *map)
{
    int head[2] = {0, 0};

    map->tab[0][0] = 0;
    while ((head[0] != map->x_max - 1 || head[1] != map->y_max - 1)) {
        printf("%d, %d\n", head[0], head[1]);
        display_map(map);
        printf("\n");
        direction(map, head);
    }
    return (1);
}
