/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** all structure for generator of dante maz
*/

#pragma once

#include "my.h"

typedef struct map_var_s {
    int error;
    int x;
    int y;
    char **map;
}map_t;
