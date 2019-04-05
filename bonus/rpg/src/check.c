/*
** EPITECH PROJECT, 2018
** src/check
** File description:
** don't forget to free at the end
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "world.h"

void    check(my_game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win->window, &(game->win->event))) {
        if (((game->win->event).type == sfEvtClosed) ||
sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->win->window);
        if (sfKeyboard_isKeyPressed(sfKeyW))
            move_forward(game, 0.05);
        if (sfKeyboard_isKeyPressed(sfKeyS))
            move_forward(game, -0.05);
        if (sfKeyboard_isKeyPressed(sfKeyD))
            move_right(game, 0.05);
        if (sfKeyboard_isKeyPressed(sfKeyA))
            move_right(game, -0.05);
        if (sfKeyboard_isKeyPressed(sfKeyE))
            move_up(game, 0.5);
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            move_up(game, -0.5);
        if (sfKeyboard_isKeyPressed(sfKeyJ))
            rotate_camera(game, 1, 0, 0);
        if (sfKeyboard_isKeyPressed(sfKeyU))
            rotate_camera(game, -1, 0, 0);
        if (sfKeyboard_isKeyPressed(sfKeyK))
            rotate_camera(game, 0, 1, 0);
        if (sfKeyboard_isKeyPressed(sfKeyI))
            rotate_camera(game, 0, -1, 0);
        if (sfKeyboard_isKeyPressed(sfKeyL))
            rotate_camera(game, 0, 0, 1);
        if (sfKeyboard_isKeyPressed(sfKeyO))
            rotate_camera(game, 0, 0, -1);
        if (sfKeyboard_isKeyPressed(sfKeyB))
            printf("x= %f, y= %f, z= %f\n",
game->camera->move.x, game->camera->move.y, game->camera->move.z);
    }
}
