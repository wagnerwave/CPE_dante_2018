/*
** EPITECH PROJECT, 2018
** src/iso
** File description:
** vim > emacs
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "my.h"

static void    rotation_cond(map_t *map, obj_t *obj)
{
    int i = 0;
    float sr = sin(map->roll_fg * M_PI / 180);
    float cr = cos(map->roll_fg * M_PI / 180);
    float sy = sin(map->yaw_fg * M_PI / 180);
    float cy = cos(map->yaw_fg * M_PI / 180);
    float sp = sin(map->pitch_fg * M_PI / 180);
    float cp = cos(map->pitch_fg * M_PI / 180);
    double tmp;

    while (i < obj->nb_point) {
        tmp = obj->point_3d[i].z;
        obj->point_3d[i].z = (sr * obj->point_3d[i].y) + (cr * tmp);
        obj->point_3d[i].y = (cr * obj->point_3d[i].y) - (sr * tmp);
        tmp = obj->point_3d[i].x;
        obj->point_3d[i].x = (cy * tmp) + (sy * obj->point_3d[i].z);
        obj->point_3d[i].z = -(sy * tmp) + (cy * obj->point_3d[i].z);
        tmp = obj->point_3d[i].x;
        obj->point_3d[i].x = (cp * tmp) - (sp * obj->point_3d[i].y);
        obj->point_3d[i].y = (sp * tmp) + (cp * obj->point_3d[i].y);
        i++;
    }
}

void    rotation(map_t *map, obj_t *obj)
{
    if (!obj)
        return ;
    if (map->roll_fg == 0 && map->yaw_fg == 0 && map->pitch_fg == 0)
        return ;
    rotation_cond(map, obj);
}

void    to_2d(my_game_t *game, room_t *room)
{
    int     n = -1;
    int     i;
    double  width_d2 = WM / 2;
    double  height_d2 = HM / 2;
    double  height_width = (double)HM / (double)WM;
    float   prospect;

    transform_camera(game, room);
    while (++n < room->nb_obj) {
        i = -1;
        while (++i < room->fix_obj[n]->nb_point) {
            prospect = (room->fix_obj[n]->point_camera[i].z == 0)
? 1 : 1.0 / (room->fix_obj[n]->point_camera[i].z);
            room->fix_obj[n]->point_2d[i].x = (room->fix_obj[n]->
point_camera[i].x * prospect) * (width_d2) * (height_width) + (width_d2);
            room->fix_obj[n]->point_2d[i].y =
(-(room->fix_obj[n]->point_camera[i].y) * prospect + 1) * (height_d2);
            room->fix_obj[n]->point_2d[i].z =
room->fix_obj[n]->point_camera[i].z;
        }
    }
}
