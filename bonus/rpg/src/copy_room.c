/*
** EPITECH PROJECT, 2018
** src/copy_room
** File description:
** epitech > epita
*/

#include <stdlib.h>
#include <fcntl.h>
#include "world.h"
#include "my.h"

const char char_obj[] = "X";

int     get_nb_of_obj(room_t *room)
{
    int nb = 0;
    int i = 0;
    int j;
    int k;

    while (i < room->y_max) {
        j = 0;
        while (j < room->z_max) {
            k = 0;
            while (k < room->x_max) {
                (room->room[i][j][k] != '*') ? nb++ : 0;
                k++;
            }
            j++;
        }
        i++;
    }
    return (nb);
}

obj_t   *get_obj_of_char(my_game_t *game, char c)
{
    int i = 0;

    while (char_obj[i]) {
        if (c == char_obj[i])
            return (game->map->obj[i]);
        i++;
    }
    return (NULL);
}

void    copy_adresse_face(obj_t *obj, int i)
{
        obj->triangle[i].point_3d[0] =
&(obj->point_3d[obj->triangle[i].indice_point[0] - 1]);
        obj->triangle[i].point_3d[1] =
&(obj->point_3d[obj->triangle[i].indice_point[1] - 1]);
        obj->triangle[i].point_3d[2] =
&(obj->point_3d[obj->triangle[i].indice_point[2] - 1]);
        obj->triangle[i].point_camera[0] =
&(obj->point_camera[obj->triangle[i].indice_point[0] - 1]);
        obj->triangle[i].point_camera[1] =
&(obj->point_camera[obj->triangle[i].indice_point[1] - 1]);
        obj->triangle[i].point_camera[2] =
&(obj->point_camera[obj->triangle[i].indice_point[2] - 1]);
        obj->triangle[i].point_2d[0] =
&(obj->point_2d[obj->triangle[i].indice_point[0] - 1]);
        obj->triangle[i].point_2d[1] =
&(obj->point_2d[obj->triangle[i].indice_point[1] - 1]);
        obj->triangle[i].point_2d[2] =
&(obj->point_2d[obj->triangle[i].indice_point[2] - 1]);
        obj->triangle[i].point_tx[0] =
&(obj->point_tx[obj->triangle[i].indice_texture[0] - 1]);
}

void    copy_face(obj_t *obj, obj_t *to_copy)
{
    int i = -1;

    while (++i < obj->nb_tr) {
        obj->triangle[i].obj = obj;
        obj->triangle[i].color = to_copy->triangle[i].color;
        obj->triangle[i].texture = to_copy->triangle[i].texture;
        obj->triangle[i].indice_point[0] = to_copy->triangle[i].indice_point[0];
        obj->triangle[i].indice_point[1] = to_copy->triangle[i].indice_point[1];
        obj->triangle[i].indice_point[2] = to_copy->triangle[i].indice_point[2];
        obj->triangle[i].indice_texture[0] =
to_copy->triangle[i].indice_texture[0];
        obj->triangle[i].indice_texture[1] =
to_copy->triangle[i].indice_texture[1];
        obj->triangle[i].indice_texture[2] =
to_copy->triangle[i].indice_texture[2];
        copy_adresse_face(obj, i);
        obj->triangle[i].point_tx[1] =
&(obj->point_tx[obj->triangle[i].indice_texture[1] - 1]);
        obj->triangle[i].point_tx[2] =
&(obj->point_tx[obj->triangle[i].indice_texture[2] - 1]);
    }
}

void    copy_info_of_obj(obj_t *obj, obj_t *to_copy)
{
    int i = -1;

    while (++i < obj->nb_point) {
        obj->point_3d[i].x = to_copy->point_3d[i].x;
        obj->point_3d[i].y = to_copy->point_3d[i].y;
        obj->point_3d[i].z = to_copy->point_3d[i].z;
        obj->point_camera[i].x = to_copy->point_camera[i].x;
        obj->point_camera[i].y = to_copy->point_camera[i].y;
        obj->point_camera[i].z = to_copy->point_camera[i].z;
        obj->point_2d[i].x = to_copy->point_2d[i].x;
        obj->point_2d[i].y = to_copy->point_2d[i].y;
        obj->point_2d[i].z = to_copy->point_2d[i].z;
    }
    i = -1;
    while (++i < obj->nb_tx) {
        obj->point_tx[i].x = to_copy->point_tx[i].x;
        obj->point_tx[i].y = to_copy->point_tx[i].y;
        obj->point_tx[i].z = to_copy->point_tx[i].z;
    }
    copy_face(obj, to_copy);
}
