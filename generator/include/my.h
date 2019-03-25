/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all function on library and project function
*/

#pragma once

#include "struct.h"

void init_map(map_t *map, char **av);
int verif_init(map_t *map);
void print_init(map_t *map);
void maze_full(map_t *map);
void print_maze(map_t *map);
void maze_generator(map_t *map);
