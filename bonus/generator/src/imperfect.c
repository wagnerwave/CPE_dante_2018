/*
** EPITECH PROJECT, 2019
** maze.c
** File description:
** maze generator
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void algo_wall(map_t *map, int y, int x)
{
    if ((rand() * (y + x) % 2 == 1)) {
        map->map[y][x] = '*';
    } else {
        map->map[y][x] = 'X';
    }
}

void init_maze(map_t *map)
{
    int x = 0;
    int end_y = map->y - 1;
    int end_x = map->x - 1;

    for (int y = 0; y < map->y; y++) {
        while (x < map->x) {
            ((x % 2) == 0) ? map->map[y][x] = '*' : 0;
            ((x % 2) == 1) ? algo_wall(map, y, x) : 0;
            x++;
        }
        x = 0;
    }
    map->map[0][0] = '*';
    map->map[end_y][end_x] = '*';
}

void print_maze(map_t *map)
{
    for (int i = 0; i < map->y; i++) {
        putchar('X');
        printf("%s", map->map[i]);
        putchar('X');
        putchar('\n');
    }
}

void maze_imperfect(map_t *map)
{
    pos_t *pos = malloc(sizeof(pos_t) + 1);

    if (pos == NULL)
        exit(84);
    init_pos(map, pos);
    init_maze(map);
    maze(map, pos);
    print_maze(map);
}
