/*
** EPITECH PROJECT, 2018
** tools
** File description:
** tools.
*/

#include <unistd.h>

int calc_distance_x(char *str)
{
    int i = 0;

    while (str[i] != '\n')
    i++;
    return (i);
}

int calc_distance_y(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            j++;
        i++;
    }
    return (j);
}

int error_player(char *str)
{
    int j = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 'P')
            j++;
        i++;
    }
    if (j != 1)
        return (84);
    return (0);
}

int error_box(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (str[i] == 'X')
            j++;
        if (str[i] == 'O')
            k++;
        i++;
    }
    if (j != k || j == 0 || k == 0)
        return (84);
    return (0);
}