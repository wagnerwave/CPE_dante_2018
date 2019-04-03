/*
** EPITECH PROJECT, 2018
** src/init_map
** File description:
** code on paper!
*/

#include <stdlib.h>
#include "dante.h"

static  void    free_at(int **tab, int nb)
{
    int i = 0;

    while (i < nb) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

static  int     **set_int_tab(map_t *map)
{
    int i = 0;
    int j = 0;
    int **itab;

    if (!(itab = malloc(sizeof(int*) * map->y_max)))
        return (NULL);
    while (i < map->y_max) {
        if (!(itab[i] = malloc(sizeof(int) * map->x_max))) {
            free_at(itab, i);
            return (NULL);
        }
        j = 0;
        while (j < map->x_max) {
            itab[i][j] = -1;
            j++;
        }
        i++;
    }
    return (itab);
}

static  case_t  *set_tab(map_t *map)
{
    case_t *tab;

    if (!(tab = malloc(sizeof(case_t) * (map->y_max * map->x_max))))
        return (NULL);
    if (!(map->itab = set_int_tab(map))) {
        free(tab);
        return (NULL);
    }
    tab[0].used = 0;
    tab[0].x = 0;
    tab[0].y = 0;
    tab[0].value = (unsigned int)(-1) - 1;
    tab[0].distance = 0;
    map->nb_case = 1;
    return (tab);
}

int     init_map(map_t **map, char const *name)
{
    int i = 0;

    if (!((*map) = malloc(sizeof(map_t))))
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
