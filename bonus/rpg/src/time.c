/*
** EPITECH PROJECT, 2018
** src/time
** File description:
** man man
*/

#include <stdlib.h>
#include "world.h"

void    make_time(my_game_t *game)
{
    return ;
    if (sfClock_getElapsedTime(game->clock).microseconds >= game->time_fg) {
        movement(game, 0, 0, 0);
        game->time_fg += 64000;
    }
}
