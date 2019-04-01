/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all function on library and project function
*/

#pragma once

#include "struct.h"

#define IMPERFECT strcmp(av[3], "imperfect")
#define PERFECT strcmp(av[3], "perfect")

void init_map(map_t *map, error_t *err, char **av);
void init_pos(map_t *map, pos_t *pos);
int verif_init(map_t *map, error_t *err);
void maze_imperfect(map_t *map);
void maze_perfect(map_t *map);
void maze(map_t *map, pos_t *pos);
void print_maze(map_t *map);
