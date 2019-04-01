/*
** EPITECH PROJECT, 2018
** src/charge_room
** File description:
** check your malloc!
*/

#include <stdlib.h>
#include <fcntl.h>
#include "world.h"
#include "my.h"

const char *name_room[1] = {"../map"};

int     set_dimension(room_t *room, char *line)
{
    int i = 0;

    if (!(room->x_max = my_getnbr(line)))
        return (0);
    while (line[i] && line[i] != ' ')
        i++;
    if (!line[i] || !(room->y_max = my_getnbr(line + i + 1)))
        return (0);
    i++;
    while (line[i] && line[i] != ' ')
        i++;
    if (!line[i] || !(room->z_max = my_getnbr(line + i + 1)))
        return (0);
    if (room->x_max <= 0 && room->y_max <= 0 && room->z_max <= 0)
        return (0);
    free(line);
    return (1);
}

int     set_each_line(room_t *room, char **tab, int fd)
{
    char *line;
    int i = 0;
    int j;
    int k;

    while (i < room->z_max) {
        if (!(tab[i] = malloc(sizeof(char) * (room->x_max + 1))))
            return (0);
        if (!(line = get_next_line(fd)))
            return (0);
        j = 0;
        k = 0;
        while (j < room->x_max) {
            tab[i][j] = (line[k]) ? line[k] : '.';
            j++;
            (line[k]) ? k++ : 0;
        }
        tab[i][j] = '\0';
        i++;
    }
    return (1);
}

room_t  *set_room(my_game_t *game, int nb)
{
    int fd = open(name_room[nb], O_RDONLY);
    char *line;
    room_t *room;

    if (fd == -1 || !(line = get_next_line(fd))) {
        (fd != -1) ? close(fd) : 0;
        return (NULL);
    }
    if (!(room = malloc(sizeof(room_t)))) {
        close(fd);
        free(line);
        return (NULL);
    }
    if (!set_dimension(room, line) || !set_tab_and_obj(game, room, fd)) {
        close(fd);
        free(line);
        free(room);
        return (NULL);
    }
    return (room);
}

room_t  **charge_room(my_game_t *game)
{
    room_t      **room;
    int         i = 0;

    game->nb_room = 1;
    game->actual_room = 0;
    if (!(room = malloc(sizeof(room_t*) * (game->nb_room))))
        return (NULL);
    while (i < game->nb_room) {
        if (!(room[i] = set_room(game, i)))
            return (NULL);
        i++;
    }
    return (room);
}
