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

void print_err_arg(void) {
    dprintf(2, "Error : too many arguments or not enought.\n");
    dprintf(2, "./generator [x] [y] [perfect/imperfect].\n");
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
        if (ac == 4 && strcmp(av[3], "perfect") != 0 && strcmp(av[3], "imperfect") != 0)
            print_err_arg();
        if (ac == 4 && strcmp(av[3], "perfect") == 0) {
            maze_perfect(map);
            return 0;
        }
        if (ac == 4 && strcmp(av[3], "imperfect") == 0) {
            maze_imperfect(map);
            return 0;
        }
        maze_perfect(map);
    }
    return 0;
}

int main(int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t) + 1);
    error_t *err = malloc(sizeof(error_t) + 1);

    srand(time(NULL));
    if (map == NULL || err == NULL) {
        dprintf(2, "Error: Malloc struct Failed.\n");
        return 84;
    }
    if (dante_star(ac, av, map, err) == 84)
        return 84;
    return 0;
}
