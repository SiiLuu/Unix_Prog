/*
** EPITECH PROJECT, 2019
** navy
** File description:
** attack gestion
*/

#include "my.h"

int status_attack(output_t *output, char *coord_attack)
{
    int k = 0;
    int i = 0;

    while (output->map[k][0] != coord_attack[1]) {
        k++;
    }
    while (output->map[0][i] != coord_attack[0]) {
        i++;
    }
    my_printf("%c%c: ", coord_attack[0], coord_attack[1]);
    if (output->map[k][i] != '.') {
        my_putstr("hit\n");
        output->map_e[k][i] = 'x';
    }
    else {
        my_putstr("missed\n");
        output->map_e[k][i] = 'o';
    }
    return (0);
}
