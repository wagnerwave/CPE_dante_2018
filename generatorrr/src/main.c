/*
** EPITECH PROJECT, 2018
** src/main
** File description:
** example of bad code:
*/

#include <time.h>
#include <unistd.h>
#include "dante.h"

void    display_map(map_t *map)
{
    size_t i = 0;

    while (i < map->y_max) {
        printf("%s\n", map->map[i]);
        i++;
    }
}

int     main(int ac, char **av)
{
    map_t *map;

    if (ac != 3)
        return (84);
    if (!(map = init_map(av)))
        return (84);
    srand(time(NULL));
    generate(map, map->x - 1, map->y - 1);
    display_map(map);
    return (0);
}
