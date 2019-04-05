/*
** EPITECH PROJECT, 2018
** src/moteur_3d/charge_obj
** File description:
** vim-epitech made by x4m3
*/

#include <stdlib.h>
#include "world.h"

const char *name_obj[] = {"doc/dalle.obj", "doc/wall.obj"};

void    free_tab_obj(obj_t **obj, int nb)
{
    int i = 0;

    if (!obj)
        return ;
    while (i < nb) {
        free(obj[i]->point_3d);
        free(obj[i]->point_2d);
        free(obj[i]->point_tx);
        free(obj[i]->triangle);
        i++;
    }
    free(obj);
}

int     charge_obj(my_game_t *game)
{
    int i = 0;

    game->obj = 2;
    if (!(game->map->obj = malloc(sizeof(obj_t*) * game->obj)))
        return (0);
    while (i < game->obj) {
        if (!(game->map->obj[i] = open_file_obj(name_obj[i]))) {
            free_tab_obj(game->map->obj, i);
            return (0);
        }
        i++;
    }
    return (1);
}
