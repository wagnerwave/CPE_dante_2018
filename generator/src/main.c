/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** for generator in dante project : alexandre wagner
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int main(int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t) + 1);

    if (ac != 3) {
        dprintf(2, "too many arguments or not enought.\n");
        return 84;
    }
    srand(time(NULL));
    init_map(map, av);
    if (verif_init(map) == 84)
        return 84;
    print_init(map); // a virée plus tard
    printf("\n =========== \n");
    maze_generator(map);
}
