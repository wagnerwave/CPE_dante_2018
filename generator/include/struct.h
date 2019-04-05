/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** all structure for generator of dante maz
*/

#pragma once

#include "my.h"

typedef struct error_s {
    int error;
}error_t;

typedef struct map_var_s {
    int x;
    int y;
    char **map;
    int **int_map;
}map_t;

typedef struct position_y_x_s {
    int x;
    int y;
    int end_x;
    int end_y;
}pos_t;
