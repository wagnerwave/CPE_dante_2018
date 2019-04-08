/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** for generator in dante project : alexandre wagner
*/

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void free_map(map_t *map)
{
    for (int i = 0; i < map->y; i++)
        free(map->map[i]);
    free(map->map);
    free(map);
}

void print_err_arg(void)
{
    printf("Error : too many arguments or not enought.");
    printf("./generator [x] [y] [perfect/imperfect].");
    exit(84);
}

int dante_star(int ac, char **av, map_t *map, error_t *err)
{
    if (ac < 3 || ac > 4)
        return 84;
    init_map(map, err, av);
    if (verif_init(map, err) == 84)
        return 84;
    if (ac >= 3) {
        if (ac == 4 && PERFECT != 0 && IMPERFECT != 0)
            print_err_arg();
        if (ac == 4 && PERFECT == 0) {
            maze_generator(map, 1);
            return 0;
        }
        if (ac == 4 && IMPERFECT == 0) {
            maze_generator(map, 0);
            return 0;
        }
        maze_generator(map, 0);
        free_map(map);
    }
    return 0;
}

int main(int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t) + 1);
    error_t *err = malloc(sizeof(error_t) + 1);

    srand(time(NULL));
    if (map == NULL || err == NULL) {
        printf("Error: Malloc struct Failed.");
        return 84;
    }
    if (dante_star(ac, av, map, err) == 84)
        return 84;
    return 0;
}
