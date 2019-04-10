/*
** EPITECH PROJECT, 2018
** dante
** File description:
** segmentation fault (core dumped)
*/

#ifndef DANTE_H
#define DANTE_H

#include <string.h>
#include <stdlib.h>

typedef struct  map_s
{
    size_t  x_max;
    size_t  y_max;
    char    **map;
}               map_t;

map_t   *init_map(char **av);
void    generate(map_t *map, int x, int y);
void    display_map(map_t *map);

#endif
