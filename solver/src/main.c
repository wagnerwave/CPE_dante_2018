/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "dante.h"

static int      map_is_posible(map_t *map)
{
    if (map->map[0][0] != '*' || map->map[map->x_max - 1][map->y_max - 1] !=
'*') {
        my_putstr("no solution found");
        return (0);
    }
    return (1);
}

static  void    display_map(map_t *map)
{
    int i = 0;

    while (i < map->y_max) {
        printf("%s", map->map[i]);
        if (i + 1 < map->y_max)
            printf("\n");
        i++;
    }
}

static  void    free_all(map_t *map)
{
    int i = 0;

    free(map->tab);
    while (i < map->y_max) {
        free(map->itab[i]);
        free(map->map[i++]);
    }
    free(map->itab);
    free(map->map);
    free(map);
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
        my_putstr("no solution found");
        return (0);
    }
    display_map(map);
    free_all(map);
    return (0);
}
