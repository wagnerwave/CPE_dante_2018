/*
** EPITECH PROJECT, 2018
** movement_camera
** File description:
** don't forget to free at the end
*/

#include "world.h"

void    move_forward(my_game_t *game, float coef)
{
    sfVector3f nor;

    if (coef == 0)
        return ;
    nor = normal_vec(game->camera->point[0], game->camera->point[1],
game->camera->point[2]);
    movement(game, nor.x * coef, 0, nor.z * coef);
}

void    move_right(my_game_t *game, float coef)
{
    sfVector3f nor;

    if (coef == 0)
        return ;
    nor = (sfVector3f){game->camera->point[1].x - game->camera->point[0].x,
game->camera->point[1].y - game->camera->point[0].y,
game->camera->point[1].z - game->camera->point[0].z};
    movement(game, nor.x * coef, nor.y * coef, nor.z * coef);
}

void    move_up(my_game_t *game, float coef)
{
    sfVector3f nor;

    if (coef == 0)
        return ;
    nor = (sfVector3f){game->camera->point[2].x - game->camera->point[0].x,
game->camera->point[2].y - game->camera->point[0].y,
game->camera->point[2].z - game->camera->point[0].z};
    movement(game, nor.x * coef, nor.y * coef, nor.z * coef);
}
