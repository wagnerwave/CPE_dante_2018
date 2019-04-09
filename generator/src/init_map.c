/*
** EPITECH PROJECT, 2018
** src/init_map
** File description:
** code on paper!
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

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

    if (!(itab = malloc(sizeof(int*) * (map->y + 1))))
        return (NULL);
    while (i < map->y + 1) {
        if (!(itab[i] = malloc(sizeof(int) * map->x))) {
            free_at(itab, i);
            return (NULL);
        }
        j = 0;
        while (j < map->x) {
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

    if (!(tab = malloc(sizeof(case_t) * (map->y * map->x))))
        return (NULL);
    if (!(map->itab = set_int_tab(map))) {
        free(tab);
        return (NULL);
    }
    tab[0].used = 0;
    tab[0].x = map->x - 1;
    tab[0].y = map->y;
    tab[0].value = 1;
    tab[0].distance = 0;
    map->nb_case = 1;
    return (tab);
}

int     init_map_second(map_t **map)
{
    if (!((*map)->tab = set_tab(*map))) {
        free_map(*map);
        return (0);
    }
    return (1);
}
