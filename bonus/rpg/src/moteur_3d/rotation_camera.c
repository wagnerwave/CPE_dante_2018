/*
** EPITECH PROJECT, 2018
** src/moteur_3d/rotation_camera
** File description:
** hello world?
*/

#include <math.h>
#include "world.h"

void    round_roll_yaw_pitch(camera_t *camera,
float roll, float yaw, float pitch)
{
    camera->roll += roll;
    camera->yaw += yaw;
    camera->pitch += pitch;
    if (camera->roll >= 360 || camera->roll < 0)
        camera->roll += (camera->roll < 0) ? 360 : -360;
    if (camera->yaw >= 360 || camera->yaw < 0)
        camera->yaw += (camera->yaw < 0) ? 360 : -360;
    if (camera->pitch >= 360 || camera->pitch < 0)
        camera->pitch += (camera->pitch < 0) ? 360 : -360;
}

void    rotate_camera(my_game_t *game, float roll, float yaw, float pitch)
{
    int i = -1;
    float sr = sin(roll * M_PI / 180);
    float cr = cos(roll * M_PI / 180);
    float sy = sin(yaw * M_PI / 180);
    float cy = cos(yaw * M_PI / 180);
    float sp = sin(pitch * M_PI / 180);
    float cp = cos(pitch * M_PI / 180);
    double tp;

    round_roll_yaw_pitch(game->camera, roll, yaw, pitch);
    while (++i < 3) {
        tp = game->camera->point[i].z;
        game->camera->point[i].z = (sr * game->camera->point[i].y) + (cr * tp);
        game->camera->point[i].y = (cr * game->camera->point[i].y) - (sr * tp);
        tp = game->camera->point[i].x;
        game->camera->point[i].x = (cy * tp) + (sy * game->camera->point[i].z);
        game->camera->point[i].z = -(sy * tp) + (cy * game->camera->point[i].z);
        tp = game->camera->point[i].x;
        game->camera->point[i].x = (cp * tp) - (sp * game->camera->point[i].y);
        game->camera->point[i].y = (sp * tp) + (cp * game->camera->point[i].y);
    }
}
