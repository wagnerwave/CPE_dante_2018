/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** rm -rf --no-preserve-root /
*/

#include <stdlib.h>

#include <stdio.h>
char    *my_itoa(int nb)
{
    int i = 0;
    int nbt = nb;
    char *tab = NULL;

    if (nb == 0)
        i = 1;
    while (nbt != 0) {
        nbt /= 10;
        i++;
    }
    if (!(tab = malloc(sizeof(char) * (i + 1))))
        return (NULL);
    tab[i] = '\0';
    while (i > 0) {
        tab[--i] = nb % 10 + '0';
        nb /= 10;
    }
    return (tab);
}
