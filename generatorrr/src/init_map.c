/*
** EPITECH PROJECT, 2018
** src/init_map
** File description:
** rm -rf --no-preserve-root /
*/

#include "dante.h"
/*
static  void    set_map(map_t *map)
{
    size_t i = 0;
    size_t j;

    while (i < map->y_max) {
        j = 0;
        while (j < map->x_max) {
            map->map[i * (map->x_max + 1) + j] = 'X';
            j++;
        }
        map->map[i * (map->x_max + 1) + j] = '\n';
        i++;
    }
    map->map[(i - 1) * (map->x_max + 1) + j] = '\0';
}
*/
map_t   *init_map(char **av)
{
    size_t i = 0;
    size_t j;
    map_t *map;

    if (!(map = malloc(sizeof(map_t))))
        return (NULL);
    if (!(map->x_max = atoi(av[1])))
        return (NULL);
    if (!(map->y_max = atoi(av[2])))
        return (NULL);
    if (!(map->map = malloc(sizeof(char*) * (map->y_max)))) {
        free(map);
        return (NULL);
    }
    while (i < map->y_max) {
        map->map[i] = malloc(map->x_max + 1);
        j = 0;
        while (j < map->x_max) {
            map->map[i][j] = 'X';
            j++;
        }
        map->map[i][j] = '\0';
        i++;
    }
    //set_map(map);
    return (map);
}
