/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** all structure for generator of dante maz
*/

#pragma once

#include <stdlib.h>
#include "my.h"

typedef struct error_s {
    int error;
}error_t;

typedef struct case_s {
    size_t  used;
    size_t  x;
    size_t  y;
    size_t  value;
    size_t  distance;
}case_t;

typedef struct map_var_s {
    case_t *tab;
    int **itab;
    int nb_case;
    int x;
    int y;
    char **map;
}map_t;

typedef struct position_y_x_s {
    int x;
    int y;
    int end_x;
    int end_y;
}pos_t;
