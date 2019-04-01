/*
** EPITECH PROJECT, 2018
** src/free_map
** File description:
** check your malloc!
*/

#include <stdlib.h>
#include "dante.h"

static void     free_map_char(char **map)
{
    int i = 0;

    if (!map)
        return ;
    while (map[i]) {
        free(map[i]);
        i++;
    }
    free(map);
}

void    free_map(map_t *map)
{
    free_map_char(map->map);
    free(map);
}
