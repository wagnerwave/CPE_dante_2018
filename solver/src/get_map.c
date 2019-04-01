/*
** EPITECH PROJECT, 2018
** src/get_map
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "dante.h"

static int      check_if_line_is_good(char *line, int *len)
{
    int i = 0;

    while (line[i]) {
        if (line[i] != 'X' && line[i] != '*')
            return (0);
        i++;
    }
    if (*len == -1)
        *len = i;
    if (i != *len)
        return (0);
    return (1);
}

static char     **get_file(int fd, int nb, int len)
{
    char    **map;
    char    *line = get_next_line(fd);

    if (!line) {
        if (!(map = malloc(sizeof(char*) * (nb + 1))))
            return (NULL);
        map[nb] = NULL;
        return (map);
    }
    if (!check_if_line_is_good(line, &len)) {
        free(line);
        return (NULL);
    }
    if (!(map = get_file(fd, nb + 1, len))) {
        free(line);
        return (NULL);
    }
    map[nb] = line;
    return (map);
}

char    **get_map(char const *name)
{
    char    **map;
    int     fd = open(name, O_RDONLY);

    if (fd == -1)
        return (NULL);
    if (!(map = get_file(fd, 0, -1))) {
        close(fd);
        return (NULL);
    }
    return (map);
}
