/*
** EPITECH PROJECT, 2018
** src/moteur_3d/transform_camera
** File description:
** fireplace 4k
*/

#include <math.h>
#include "world.h"

void    transform_move_camera(my_game_t *game, room_t *room)
{
    int i = 0;
    int j;

    while (i < room->nb_obj) {
        j = 0;
        while (j < room->fix_obj[i]->nb_point) {
            room->fix_obj[i]->point_camera[j].x =
room->fix_obj[i]->point_3d[j].x - game->camera->move.x;
            room->fix_obj[i]->point_camera[j].y =
room->fix_obj[i]->point_3d[j].y - game->camera->move.y;
            room->fix_obj[i]->point_camera[j].z =
room->fix_obj[i]->point_3d[j].z - game->camera->move.z;
            j++;
        }
        i++;
    }
}

void    make_rotation(room_t *room, float *tab, int i, int j)
{
    double tmp;

    tmp = room->fix_obj[i]->point_camera[j].z;
    room->fix_obj[i]->point_camera[j].z =
(tab[0] * room->fix_obj[i]->point_camera[j].y) + (tab[1] * tmp);
    room->fix_obj[i]->point_camera[j].y =
(tab[1] * room->fix_obj[i]->point_camera[j].y) - (tab[0] * tmp);
    tmp = room->fix_obj[i]->point_camera[j].x;
    room->fix_obj[i]->point_camera[j].x =
(tab[3] * tmp) + (tab[2] * room->fix_obj[i]->point_camera[j].z);
    room->fix_obj[i]->point_camera[j].z =
-(tab[2] * tmp) + (tab[3] * room->fix_obj[i]->point_camera[j].z);
    tmp = room->fix_obj[i]->point_camera[j].x;
    room->fix_obj[i]->point_camera[j].x =
(tab[5] * tmp) - (tab[4] * room->fix_obj[i]->point_camera[j].y);
    room->fix_obj[i]->point_camera[j].y =
(tab[4] * tmp) + (tab[5] * room->fix_obj[i]->point_camera[j].y);
}

void    transform_rotation_camera(my_game_t *game, room_t *room)
{
    int i = -1;
    int j;
    float tab[6] = {sin(-game->camera->roll * M_PI / 180),
cos(-game->camera->roll * M_PI / 180), sin(-game->camera->yaw * M_PI / 180),
cos(-game->camera->yaw * M_PI / 180), sin(-game->camera->pitch * M_PI / 180),
cos(-game->camera->pitch * M_PI / 180)};

    while (++i < room->nb_obj) {
        j = -1;
        while (++j < room->fix_obj[i]->nb_point) {
            make_rotation(room, tab, i, j);
        }
    }
}

void    transform_camera(my_game_t *game, room_t *room)
{
    transform_move_camera(game, room);
    transform_rotation_camera(game, room);
}
