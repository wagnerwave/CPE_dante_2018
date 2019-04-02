/*
** EPITECH PROJECT, 2018
** src/init_map
** File description:
** code on paper!
*/

#include <stdlib.h>
#include "dante.h"

static  case_t  *set_tab(map_t *map)
{
    case_t *tab;

    if (!(tab = malloc(sizeof(case_t*) * (map->y_max * map->x_max))))
        return (NULL);
    tab[0] = NULL;
    map->nb_case = 0;
    return (tab);
}

int     init_map(map_t **map, char const *name)
{
    int i = 0;

    if (!((*map) = malloc(sizeof(map_t*))))
        return (0);
    if (!((*map)->map = get_map(name))) {
        free(*map);
        return (0);
    }
    while ((*map)->map[0][i])
        i++;
    (*map)->x_max = i;
    i = 0;
    while ((*map)->map[i])
        i++;
    (*map)->y_max = i;
    if (!((*map)->tab = set_tab(*map))) {
        free_map(*map);
        return (0);
    }
    return (1);
}
