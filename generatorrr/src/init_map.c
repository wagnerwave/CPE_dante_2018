/*
** EPITECH PROJECT, 2018
** src/init_map
** File description:
** rm -rf --no-preserve-root /
*/

#include "dante.h"

map_t   *init_map(char **av)
{
    size_t i = 0;
    size_t j;
    map_t *map;

    if (!(map = malloc(sizeof(map_t))))
        return (NULL);
    if (!(map->x = atoi(av[1])))
        return (NULL);
    if (!(map->y = atoi(av[2])))
        return (NULL);
    if (!(map->map = malloc(sizeof(char*) * (map->y)))) {
        free(map);
        return (NULL);
    }
    while (i < map->y) {
        map->map[i] = malloc(map->x + 1);
        j = 0;
        while (j < map->x) {
            map->map[i][j] = 'X';
            j++;
        }
        map->map[i][j] = '\0';
        i++;
    }
    return (map);
}
