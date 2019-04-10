/*
** EPITECH PROJECT, 2018
** src/generate
** File description:
** example of bad code:
*/

#include "dante.h"

const int pos[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
const int sch[4][5][2] = {{{0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}},
                          {{0, 1}, {1, 0}, {0, -1}, {1, 1}, {1, -1}},
                          {{1, 0}, {0, 1}, {-1, 0}, {1, 1}, {-1, 1}},
                          {{-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {-1, -1}}};

static  int     is_posible(map_t *map, int x, int y, size_t nb)
{
    size_t  i = 0;

    if (x + pos[nb][0] < 0 || x + pos[nb][0] >= (int)map->x ||
y + pos[nb][1] < 0 || y + pos[nb][1] >= (int)map->y)
        return (0);
    if (map->map[y + pos[nb][1]][x + pos[nb][0]] != 'X')
        return (0);
    while (i < 5) {
        if (x + pos[nb][0] + sch[nb][i][0] < 0 || x + pos[nb][0] + sch[nb][i][0]
>= (int)map->x || y + pos[nb][1] + sch[nb][i][1] < 0 || y + pos[nb][1] +
sch[nb][i][1] >= (int)map->y) {
            i++;
            continue ;
        }
        if (map->map[(y + pos[nb][1] + sch[nb][i][1])]
[(x + pos[nb][0] + sch[nb][i][0])] != 'X')
            return (0);
        i++;
    }
    return (1);
}

void    generate(map_t *map, int x, int y)
{
    int     tab[4] = {0, 0, 0, 0};
    int     i = -1;
    size_t  tmp;

    map->map[y][x] = '*';
    while (++i < 4) {
        if (is_posible(map, x, y, i) && x + pos[i][0] == 0 &&
y + pos[i][1] == 0) {
            tab[i] = 1;
            generate(map, x + pos[i][0], y + pos[i][1]);
            break;
        }
    }
    while (tab[0] == 0 || tab[1] == 0 || tab[2] == 0 || tab[3] == 0) {
        tmp = rand() % 4;
        if (tab[tmp] == 1)
            continue;
        tab[tmp] = 1;
        if (is_posible(map, x, y, tmp))
            generate(map, x + pos[tmp][0], y + pos[tmp][1]);
    }
}
