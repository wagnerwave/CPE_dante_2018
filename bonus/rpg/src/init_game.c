/*
** EPITECH PROJECT, 2018
** init_game
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include <stdlib.h>
#include "world.h"

int     init_game(my_game_t *game)
{
    if (!(game->room = charge_room(game)))
        return (0);
    return (1);
}
