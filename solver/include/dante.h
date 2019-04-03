/*
** EPITECH PROJECT, 2018
** dante
** File description:
** segmentation fault (core dumped)
*/

#ifndef DANTE_H
#define DANTE_H

#include <string.h>

typedef struct  case_s
{
    size_t  used;
    size_t  x;
    size_t  y;
    size_t  value;
    size_t  distance;
}               case_t;

typedef struct  map_s
{
    case_t  *tab;
    int     **itab;
    int     nb_case;
    int     x_max;
    int     y_max;
    char    **map;
}               map_t;

char    **get_map(char const *name);
void    free_map(map_t *map);
int     init_map(map_t **map, char const *name);
int     resolve_map(map_t *map);

#endif
