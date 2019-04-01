/*
** EPITECH PROJECT, 2018
** src/update
** File description:
** you're a bad developer
*/

#include "world.h"

void    clear_buff(my_framebuff_t *buff, double *z_buff)
{
    int i = 0;
    int len = WM * HM;

    while (i < len) {
        z_buff[i] = -1;
        buff->pixels[i * 4] = 0;
        buff->pixels[i * 4 + 1] = 0;
        buff->pixels[i * 4 + 2] = 0;
        buff->pixels[i * 4 + 3] = 0;
        i++;
    }
}

void    update(my_game_t *game)
{
    sfRenderWindow_clear(game->win->window, sfBlack);
    sfTexture_updateFromPixels(game->win->texture, game->win->framebuff->pixels,
WM, HM, 0, 0);
    sfRenderWindow_drawSprite(game->win->window, game->win->sprite, NULL);
    //function_draw_hub
    sfRenderWindow_display(game->win->window);
}
