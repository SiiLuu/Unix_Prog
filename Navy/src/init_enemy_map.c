/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** navy project
*/

#include "my.h"

char *mid(int k, output_t *output)
{
    int i = 2;

    output->map_e[k] = malloc(sizeof(char) * 19);
    output->map_e[k][0] = (k - 1) + '0';
    output->map_e[k][1] = '|';
    while (i < 17) {
        (i % 2 != 0) ? (output->map_e[k][i] = ' ') :
        (output->map_e[k][i] = '.');
        i++;
    }
    output->map_e[k][17] = '\n';
    output->map_e[k][18] = '\0';
    return (output->map_e[k]);
}

void init_enemy_map(output_t *output)
{
    int k = 0;

    while (k < 10) {
        if (k == 0)
            output->map_e[k] = " |A B C D E F G H\n";
        if (k == 1)
            output->map_e[k] = "-+---------------\n";
        if (k > 1)
            output->map_e[k] = mid(k, output);
        k++;
    }
}