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
void maze_generator(map_t *map, int bool);
void btree(map_t *map, pos_t *pos, int c);
int init_map_second(map_t **map);
int resolve_map(map_t *map);
void free_map(map_t *map);
int my_pow(int nb, int p);
void print_maze(map_t *map);
void generate(map_t *map, int x, int y);
