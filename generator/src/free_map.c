/*
** EPITECH PROJECT, 2018
** src/free_map
** File description:
** check your malloc!
*/

#include <stdlib.h>
#include "struct.h"

void    free_map(map_t *map)
{
    int i = 0;

    if (!map)
        return ;
    while (map->map[i]) {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    free(map);
}
