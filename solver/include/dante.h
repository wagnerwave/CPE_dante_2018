/*
** EPITECH PROJECT, 2018
** dante
** File description:
** segmentation fault (core dumped)
*/

#ifndef DANTE_H
#define DANTE_H

typedef struct  map_s
{
    char    **map;
    int     **tab;
    int     x_max;
    int     y_max;
}               map_t;

char    **get_map(char const *name);
void    free_map(map_t *map);
int     init_map(map_t **map, char const *name);
int     resolve_map(map_t *map);
void     display_map(map_t *map);

#endif