/*
** EPITECH PROJECT, 2019
** navy
** File description:
** fonction to print my boat in vertical
*/

#include "my.h"

void vertical_boat_1(output_t *output, int k, int i, char **cord)
{
    int j = 0;

    while (j + '0' < cord[0][0]) {
        output->map[k + j][i] = cord[0][0];
        j++;
    }
}

void vertical_boat_2(output_t *output, int k, int i, char **cord)
{
    int j = 0;

    while (j + '0' < cord[1][0]) {
        output->map[k + j][i] = cord[1][0];
        j++;
    }
}

void vertical_boat_3(output_t *output, int k, int i, char **cord)
{
    int j = 0;

    while (j + '0' < cord[2][0]) {
        output->map[k + j][i] = cord[2][0];
        j++;
    }
}

void vertical_boat_4(output_t *output, int k, int i, char **cord)
{
    int j = 0;

    while (j + '0' < cord[3][0]) {
        output->map[k + j][i] = cord[3][0];
        j++;
    }
}