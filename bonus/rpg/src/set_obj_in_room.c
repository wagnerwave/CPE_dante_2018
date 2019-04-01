/*
** EPITECH PROJECT, 2018
** src/set_obj_in_room
** File description:
** don't forget to free at the end
*/

#include <stdlib.h>
#include <fcntl.h>
#include "world.h"
#include "my.h"

void    copy_obj(obj_t *obj, obj_t *to_copy)
{
    if (!to_copy) {
        obj = NULL;
        return ;
    }
    obj->nb_point = to_copy->nb_point;
    obj->nb_tr = to_copy->nb_tr;
    obj->nb_tx = to_copy->nb_tx;
    obj->point_3d = malloc(sizeof(sfVector3f) * obj->nb_point);
    obj->point_camera = malloc(sizeof(sfVector3f) * obj->nb_point);
    obj->point_2d = malloc(sizeof(sfVector3f) * obj->nb_point);
    obj->point_tx = malloc(sizeof(sfVector3f) * obj->nb_tx);
    obj->triangle = malloc(sizeof(triangle_t) * obj->nb_tr);
    copy_info_of_obj(obj, to_copy);
}

void    move_obj_to(obj_t *obj, int y, int z, int x)
{
    int i = 0;

    if (!obj || obj->nb_point <= 0)
        return ;
    while (i < obj->nb_point) {
        obj->point_3d[i].x += x + 0.5;
        obj->point_3d[i].y += y + 0.5 + 0.01;
        obj->point_3d[i].z += z + 0.5;
        i++;
    }
}

void    set_all_obj_in_room(my_game_t *game, room_t *room)
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
                (room->room[i][j][k] != '*') ?
copy_obj(room->fix_obj[nb], get_obj_of_char(game, room->room[i][j][k])) : 0;
                (room->room[i][j][k] != '*') ?
move_obj_to(room->fix_obj[nb++], i, j, k) : 0;
                k++;
            }
            j++;
        }
        i++;
    }
}

int     set_obj_in_room(my_game_t *game, room_t *room)
{
    int i = 0;

    room->nb_obj = get_nb_of_obj(room);
    if (room->nb_obj <= 0) {
        room->fix_obj = NULL;
        return (0);
    }
    if (!(room->fix_obj = malloc(sizeof(obj_t*) * room->nb_obj)))
        return (0);
    while (i < room->nb_obj) {
        if (!(room->fix_obj[i] = malloc(sizeof(obj_t))))
            return (0);
        i++;
    }
    set_all_obj_in_room(game, room);
    return (1);
}

int     set_tab_and_obj(my_game_t *game, room_t *room, int fd)
{
    int i = 0;

    printf("G\n");
    if (!(room->room = malloc(sizeof(char**) * room->y_max)))
        return (0);
    printf("H\n");
    while (i < room->y_max) {
        if (!(room->room[i] = malloc(sizeof(char*) * room->z_max)))
            return (0);
    	printf("a\n");
        free(get_next_line(fd));
    	printf("b\n");
        if (!set_each_line(room, room->room[i], fd))
            return (0);
    	printf("c\n");
        i++;
    }
    printf("I\n");
    if (!set_obj_in_room(game, room))
        return (0);
    return (1);
}
