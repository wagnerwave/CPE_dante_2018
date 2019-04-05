/*
** EPITECH PROJECT, 2018
** src/display
** File description:
** rm -rf --no-preserve-root /
*/

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "world.h"

sfVector3f      normal_vec(sfVector3f a, sfVector3f b, sfVector3f c)
{
    sfVector3f ab = {b.x - a.x, b.y - a.y, b.z - a.z};
    sfVector3f ac = {c.x - a.x, c.y - a.y, c.z - a.z};

    return ((sfVector3f){ab.y * ac.z - ab.z * ac.y,
            ab.z * ac.x - ab.x * ac.z,
            ab.x * ac.y - ab.y * ac.x});
}

int     is_drawable(triangle_t *tri)
{
    /*if (tri->point_2d[0]->z <= 0 || tri->point_2d[0]->y < 0 ||
tri->point_2d[0]->y >= HM || tri->point_2d[0]->x < 0 || tri->point_2d[0]->x >=
WM || tri->point_2d[1]->z <= 0 || tri->point_2d[1]->y < 0 || tri->point_2d[1]->y
>= HM || tri->point_2d[1]->x < 0 || tri->point_2d[1]->x >= WM ||
tri->point_2d[2]->z <= 0 || tri->point_2d[2]->y < 0 || tri->point_2d[2]->y >= HM
|| tri->point_2d[2]->x < 0 || tri->point_2d[2]->x >= WM)
        return (0);*/
    if (tri->point_2d[0]->z <= 0 || tri->point_2d[1]->z <= 0 ||
tri->point_2d[2]->z <= 0)
        return (0);
    if (((tri->point_2d[0]->x < 0) && (tri->point_2d[1]->x < 0) &&
(tri->point_2d[2]->x < 0)) || ((tri->point_2d[0]->y < 0) &&
(tri->point_2d[1]->y < 0) && (tri->point_2d[2]->y < 0)))
        return (0);
    if (((tri->point_2d[0]->x >= WM) && (tri->point_2d[1]->x >= WM) &&
(tri->point_2d[2]->x >= WM)) || ((tri->point_2d[0]->y >= HM) &&
(tri->point_2d[1]->y >= HM) && (tri->point_2d[2]->y >= HM)))
        return (0);
    return (1);
}

static void     display_triangle_in_map(my_game_t *game, triangle_t *tri)
{
    double res;
    sfVector3f pos[] = {*(tri->point_2d[0]), *(tri->point_2d[1]),
*(tri->point_2d[2]), *(tri->point_2d[0]), *(tri->point_2d[0]),
*(tri->point_2d[0])};
    sfVector3f normal = normal_vec(*(tri->point_camera[0]),
*(tri->point_camera[1]), *(tri->point_camera[2]));

    res = normal.z;
    if (res < 0)
        res *= -1;
    game->map->lum = 1;//res;
    game->map->ptr_tri = tri;
    if (tri->point_tx[0] == NULL || tri->point_tx[1] == NULL ||
tri->point_tx[2] == NULL)
        tri->texture = -1;
    if (tri->texture == -1) {
        draw_triangle(game, pos, tri->color);
        return ;
    }
    draw_poly(game, tri);
}

void    display(my_game_t *game, obj_t *obj)
{
    int i = 0;

    while (i < obj->nb_tr) {
        if (is_drawable(&(obj->triangle[i])))
            display_triangle_in_map(game, &(obj->triangle[i]));
        i++;
    }
}
