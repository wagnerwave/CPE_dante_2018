/*
** EPITECH PROJECT, 2018
** src/init_texture
** File description:
** segmentation fault (core dumped)
*/

#include <stdlib.h>
#include "world.h"

const char      *img_name[13] = {"img/grass.png", "img/diamant.jpg",
"img/face1.jpg", "img/face2.jpg", "img/face3.jpg", "img/face4.jpg",
"img/face5.jpg", "img/face6.jpg", "img/pine-tree-leaf.jpg",
"img/pine-tree-bark.jpg", "img/ground.jpg", "img/cobble.png",
"img/wall2.png"};

void    set_img(my_game_t *game)
{
    int i = 0;

    game->nb_col_max = 10;
    game->nb_img = 13;
    if (game->nb_img < 1 ||
    !(game->img = malloc(sizeof(sfImage*) * game->nb_img)))
        return ;
    while (i < game->nb_img) {
        game->img[i] = sfImage_createFromFile(img_name[i]);
        i++;
    }
}

int     init_all_3d(my_game_t *game)
{
    game->nb_img = 0;
    game->map->obj = NULL;
    if (!(game->camera = malloc(sizeof(camera_t))))
        return (0);
    game->camera->point[0] = (sfVector3f){0, 0, 0};
    game->camera->point[1] = (sfVector3f){1, 0, 0};
    game->camera->point[2] = (sfVector3f){0, 1, 0};
    game->camera->move = (sfVector3f){0, 0, 0};
    game->camera->roll = 0;
    game->camera->yaw = 0;
    game->camera->pitch = 0;
    game->room = 0;
    if (!(charge_obj(game)))
        return (0);
    set_img(game);
    return (1);
}
