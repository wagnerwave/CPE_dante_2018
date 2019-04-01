/*
** EPITECH PROJECT, 2019
** maze.c
** File description:
** maze generator
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"


int compt_asterix(map_t *map , int y)
{
    int nb_ast = 0;

    for (int x = 0; x < map->x; x++)
        (map->map[y][x] == '*') ? nb_ast++ : 0;
    return nb_ast;
}

void mem_maze(map_t *map)
{
    for (int y = 0; y < map->y; y++)
        memset(map->map[y], map->x, sizeof(char));
}

void algo_perfect(map_t *map, int y, int x)
{
    int r = 0;

    r = rand() % map->x;
    ((y % 2) == 0) ? map->map[y][x] = '*' : 0;
    ((y % 2) == 1) ? map->map[y][x] = 'X' : 0;
    if (compt_asterix(map, y) == 0 && x == map->x - 1) {
        x = r;
        map->map[y][x] = '*';
    }
}

void init_perfect_maze(map_t *map, pos_t *pos)
{
    int y = 0;

    mem_maze(map);
    for (int x = 0; x < map->x; x++)
        for (y = 0; y < map->y; y++)
            algo_perfect(map, y, x);
    map->map[0][0] = '*';
    map->map[pos->end_y][pos->end_x] = '*';
}

void maze_perfect(map_t *map)
{
    pos_t *pos = malloc(sizeof(pos_t) + 1);

    if (pos == NULL)
        exit(84);
    init_pos(map, pos);
    init_perfect_maze(map, pos);
    printf("%d 2 %d\n\n", map->x, map->y);
    print_maze(map);
    putchar('\n');
    print_maze(map);
}
