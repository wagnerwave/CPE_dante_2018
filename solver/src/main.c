/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"
#include "dante.h"

static int      map_is_posible(map_t *map)
{
    if (map->map[0][0] == 'x' || map->map[map->x_max - 1][map->y_max - 1] ==
'x') {
        my_putstr("no solution found\n");
        return (0);
    }
    return (1);
}

void     display_map(map_t *map)
{
    int i = 0;

    while (i < map->y_max) {
        printf("%s\n", map->map[i]);
        i++;
    }
}

int     main(int ac, char **av)
{
    map_t *map = NULL;

    if (ac != 2)
        return (84);
    if (!init_map(&map, av[1]))
        return (84);
    if (!map_is_posible(map)) {
        free_map(map);
        return (0);
    }
    if (!(resolve_map(map))) {
        my_putstr("no solution found\n");
        return (0);
    }
    display_map(map);
    return (0);
}
