/*
** EPITECH PROJECT, 2018
** src/movement
** File description:
** man man
*/

#include <stdlib.h>
#include "world.h"

void    set_around(my_game_t *game, char *around)
{
    double cord[11][3] = {{0, -1, 0}, {0, -1.1, 0}, {0, 1, 0}, {1, 0, 0},
{1, -1, 0}, {-1, 0, 0}, {-1, -1, 0}, {0, 0, 1}, {0, -1, 1}, {0, 0, -1},
{0, -1, -1}};
    int i = 0;

    while (i < 11) {
        if ((int)(game->camera->move.x + cord[i][0]) >= 0 &&
(int)(game->camera->move.x + cord[i][0]) < game->room[game->actual_room]->x_max
&& (int)(game->camera->move.y + cord[i][1]) >= 0 && (int)(game->camera->move.y
+ cord[i][1]) < game->room[game->actual_room]->y_max &&
(int)(game->camera->move.z + cord[i][2]) >= 0 && (int)(game->camera->move.z +
cord[i][2]) < game->room[game->actual_room]->z_max)
            around[i] = game->room[game->actual_room]->room[(int)(game->camera->
move.y + cord[i][1])][(int)(game->camera->move.z + cord[i][2])][(int)(game->
camera->move.x + cord[i][0])];
        i++;
    }
}

void    check_x(my_game_t *game, char *around, double *x)
{
    if (((around[3] && around[3] != '.') || (around[4] && around[4]
== 'O')) && game->camera->move.x + *x >= (int)game->camera->move.x + 1)
        *x = (int)game->camera->move.x + 1 - game->camera->move.x - 0.01;
    if (((around[5] && around[5] != '.') || (around[6] && around[6] ==
'O')) && game->camera->move.x - 1 + *x <= (int)game->camera->move.x - 1)
        *x = (int)game->camera->move.x - 1 -(game->camera->move.x - 1);
}

void    check_y(my_game_t *game, char *around, double *y)
{
    if (around[0] && around[0] == '*' &&
game->camera->move.y - 1 + *y <= (int)game->camera->move.y - 1)
        *y = (int)game->camera->move.y - 1 -(game->camera->move.y - 1);
    if (around[1] && around[1] == 'X' &&
game->camera->move.y - 1 + *y <= (int)game->camera->move.y - 1)
        *y = (int)game->camera->move.y - 1 -(game->camera->move.y - 1);
    if (around[2] && around[2] != '.' &&
game->camera->move.y + *y >= (int)game->camera->move.y + 1)
        *y = (int)game->camera->move.y + 1 - game->camera->move.y - 0.01;
}

void    check_z(my_game_t *game, char *around, double *z)
{
    if (((around[7] && around[7] != '.') || (around[8] && around[8] ==
'O')) && game->camera->move.z + *z >= (int)game->camera->move.z + 1)
        *z = (int)game->camera->move.z + 1 - game->camera->move.z - 0.01;
    if (((around[9] && around[9] != '.') || (around[10] && around[10]
== 'O')) && game->camera->move.z - 1 + *z <= (int)game->camera->move.z - 1)
        *z = (int)game->camera->move.z - 1 -(game->camera->move.z - 1);
}

void    movement(my_game_t *game, double x, double y, double z)
{
    char around[11] = {'\0'};

    game->map->update = 1;
    set_around(game, around);
    if (x != 0)
        check_x(game, around, &x);
    if (y != 0)
        check_y(game, around, &y);
    if (z != 0)
        check_z(game, around, &z);
    game->camera->move.x += x;
    game->camera->move.y += y;
    game->camera->move.z += z;
}
