/*
** EPITECH PROJECT, 2018
** world
** File description:
** try not to segfault, good luck :)
*/

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

const char      *img_name[13];
const char      *img_button[13];
const sfColor   color[10];

typedef struct  arg_interpolation_s
{
    double iza;
    double uiza;
    double viza;
    double dizdx;
    double duizdx;
    double dvizdx;
    double xa;
    double xb;
    double dxdya;
    double dxdyb;
    double dizdya;
    double duizdya;
    double dvizdya;
    int y1;
    int y2;
    int y1i;
    int y2i;
    int y3i;
}               arg_interpolation_t;

typedef struct  vector4f_s
{
    double x;
    double y;
    double z;
    double t;
    double bcy;
    double cbx;
    double cay;
    double acx;
    double div;
    sfVector3f c_point;
    sfVector3f a_uv;
    sfVector3f b_uv;
    sfVector3f c_uv;
    sfVector3f sz;
    sfVector3f su;
    sfVector3f sv;
}             vector4f_t;

typedef struct  my_framebuff_s
{
    int         width;
    int         height;
    sfUint8     *pixels;
}               my_framebuff_t;

typedef struct  obj_s obj_t;

typedef struct  triangle_s
{
    obj_t       *obj;
    sfVector3f  *point_3d[3];
    sfVector3f  *point_camera[3];
    sfVector3f  *point_2d[3];
    sfVector3f  *point_tx[3];
    sfColor     color;
    int         texture;
    int         indice_point[3];
    int         indice_texture[3];
}               triangle_t;

typedef struct  my_window_s
{
    sfRenderWindow      *window;
    sfEvent             event;
    sfTexture           *texture;
    sfSprite            *sprite;
    my_framebuff_t      *framebuff;
    double              *z_buff;
    triangle_t          **t_buff;
    sfVector2u          pos;
}               my_window_t;

typedef struct  obj_s
{
    int         nb_point;
    int         nb_tr;
    int         nb_tx;
    sfVector3f  *point_3d;
    sfVector3f  *point_camera;
    sfVector3f  *point_2d;
    sfVector3f  *point_tx;
    triangle_t  *triangle;
}               obj_t;

typedef struct  camera_s
{
    sfVector3f  move;
    sfVector3f  point[3];
    float       roll;
    float       yaw;
    float       pitch;
}               camera_t;

typedef struct  map_s
{
    float       roll_fg;
    float       yaw_fg;
    float       pitch_fg;
    float       roll;
    float       yaw;
    float       pitch;
    int         update;
    double      move_point_x;
    double      move_point_y;
    double      move_point_z;
    double      enlargement;
    double      lum;
    triangle_t  *ptr_tri;
    obj_t       **obj;
}               map_t;

typedef struct  room_s
{
    obj_t       **fix_obj;
    char        ***room;
    int         x_max;
    int         y_max;
    int         z_max;
    int         nb_obj;
}               room_t;

typedef struct  my_game_s
{
    room_t          **room;
    my_window_t     *win;
    map_t           *map;
    sfImage         **img;
    camera_t        *camera;
    sfClock         *clock;
    sfInt64         time_fg;
    int             obj;
    int             nb_room;
    int             actual_room;
    int             nb_img;
    int             nb_col_max;
}               my_game_t;

int     window(void);
int     init_all_3d(my_game_t *game);
void    put_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color);
void    put_pixel3d(my_game_t *game, sfVector3f cord, sfColor color);
void    square(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color);
void    clear_buff(my_framebuff_t *buff, double *z_buff);
void    clear_z_buff(double *z_buff);
void    clear_t_buff(triangle_t **t_buff);
void    transform_move(my_game_t *game, obj_t *obj);
void    transform_lower(my_game_t *game, obj_t *obj);
void    rotation(map_t *map, obj_t *obj);
void    display(my_game_t *game, obj_t *obj);
my_game_t        *set_game(void);
void    update(my_game_t *game);
void    check(my_game_t *game);
void horz_line(my_game_t *game, sfVector3f pos, vector4f_t nor, sfColor color);
void    draw_triangle(my_game_t *game, sfVector3f *pos, sfColor color);
void    draw_poly(my_game_t *game, triangle_t *tri);
void    draw_poly_interpolation(my_game_t *game, triangle_t *tri,
arg_interpolation_t *arg);
void    init_draw_poly(my_game_t *game, triangle_t *tri, double *tab);
double  my_getfloat(char *str);
obj_t   *init_obj(void);
int     get_nbr_arg(obj_t *obj, char *name);
int     set_obj(obj_t *obj, char *name);
void    set_triangle_tx(obj_t *obj, char **array, int nb);
void    set_point(obj_t *obj, char **array);
void    set_point_tx(obj_t *obj, char **array);
void    free_array(char **array);
int     cond_inter(double *tab, int y1i, int y2i, int y3i);
void    init_arg(arg_interpolation_t *arg, double *tab);
int     calc_side(double *tab);
void    set_value_game(my_game_t *game);
obj_t   *open_file_obj(const char *name);
void    set_img(my_game_t *game);
void    draw_circle(my_framebuff_t *buff, sfVector2i cnt, int *tab,
sfColor color);
void    draw_line(my_framebuff_t *buff, sfVector2f *pos, int r, sfColor color);
int     charge_obj(my_game_t *game);
sfVector3f      normal_vec(sfVector3f a, sfVector3f b, sfVector3f c);
void    move_forward(my_game_t *game, float coef);
void    move_right(my_game_t *game, float coef);
void    move_up(my_game_t *game, float coef);
void    rotation_roll(my_game_t *game, float coef);
void    rotation_yaw(my_game_t *game, float coef);
void    rotation_pitch(my_game_t *game, float coef);
void    rotate_camera(my_game_t *game, float roll, float yaw, float pitch);
void    make_time(my_game_t *game);
int     init_game(my_game_t *game);
room_t  **charge_room(my_game_t *game);
void    transform_camera(my_game_t *game, room_t *room);
void    to_2d(my_game_t *game, room_t *room);
void    display_room(my_game_t *game);
void    movement(my_game_t *game, double x, double y, double z);
void    copy_obj(obj_t *obj, obj_t *to_copy);
void    move_obj_to(obj_t *obj, int y, int z, int x);
void    set_all_obj_in_room(my_game_t *game, room_t *room);
int     set_obj_in_room(my_game_t *game, room_t *room);
int     set_tab_and_obj(my_game_t *game, room_t *room, int fd);
int     get_nb_of_obj(room_t *room);
obj_t   *get_obj_of_char(my_game_t *game, char c);
void    copy_adresse_face(obj_t *obj, int i);
void    copy_face(obj_t *obj, obj_t *to_copy);
void    copy_info_of_obj(obj_t *obj, obj_t *to_copy);
int     set_each_line(room_t *room, char **tab, int fd);

#define WM 480
//#define WM 1920
//1920  1280  960  480
#define HM 270
//#define HM 1080
//1080  720   540  270

#endif
