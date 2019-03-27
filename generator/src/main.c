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

int main(int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t) + 1);
    error_t *err = malloc(sizeof(error_t) + 1);

    srand(time(NULL));
    if (map == NULL || err == NULL) {
        dprintf(2, "Error: Malloc struct Failed.\n");
        return 84;
    }
    if (ac != 4 ||
(strcmp(av[3], "perfect") != 0 && strcmp(av[3], "imperfect") != 0)) {
        dprintf(2, "Error : too many arguments or not enought.\n\n");
        dprintf(2, "./generator [ximperfect] [y] [perfect/imperfect].\n");
        return 84;
    }
    init_map(map, err, av);
    if (verif_init(map, err) == 84)
        return 84;
    maze_generator(map);
}
