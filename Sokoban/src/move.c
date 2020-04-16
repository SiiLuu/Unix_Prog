/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** mobe up, down, left, right
*/

#include "../include/my_sokoban.h"

void move_up(char *str)
{
    int i = 0;
    int distance = 0;

    for (;str[i] != 'P'; i++);
    distance = calc_distance_x(str);
    if ((str[i - distance - 1] == '#') ||
        (str[i - distance - 1] == 'O') ||
        (str[i - distance - 1] == 'X' && str[i - (2*distance) - 2] == '#'));
    else if (str[i - distance -1] == 'X' &&
        (str[i - (2*distance) - 2] == ' ' ||
            str[i - (2*distance) - 2] == 'O')) {
        str[i - (2*distance) - 2] = str[i - distance - 1];
        str[i - distance - 1] = str[i];
        str[i] = ' ';
    }
    else {
        str[i - distance - 1] = 'P';
        str[i] = ' ';
    }
}

void move_down(char *str)
{
    int i = 0;
    int distance = 0;

    for (;str[i] != 'P'; i++);
    distance = calc_distance_x(str);
    if ((str[i + distance + 1] == '#') ||
        (str[i + distance + 1] == 'O') ||
        (str[i + distance + 1] == 'X' && str[i + (2*distance) + 2] == '#'));
    else if (str[i + distance +1] == 'X' &&
        (str[i + (2*distance) + 2] == ' ' ||
            str[i + (2*distance) + 2] == 'O')) {
        str[i + (2*distance) + 2] = str[i + distance + 1];
        str[i + distance + 1] = str[i];
        str[i] = ' ';
    }
    else {
        str[i + distance + 1] = 'P';
        str[i] = ' ';
    }
}

void move_left(char *str)
{
    int i = 0;

    for (;str[i] != 'P'; i++);
    if ((str[i - 1] == '#') ||
        (str[i - 1] == 'O') ||
        (str[i - 1] == 'X' && str[i - 2] == '#'));
    else if (str[i - 1] == 'X' &&
        (str[i - 2] == ' ' || str[i - 2] == 'O')) {
        str[i - 2] = str[i - 1];
        str[i - 1] = str[i];
        str[i] = ' ';
    }
    else {
        str[i - 1] = 'P';
        str[i] = ' ';
    }
}

void move_right(char *str)
{
    int i = 0;

    for (;str[i] != 'P'; i++);
    if ((str[i + 2] == '\n') ||
        (str[i + 1] == '#') ||
        (str[i + 1] == 'O') ||
        (str[i + 1] == 'X' && str[i + 3] == '\n'));
    else if (str[i + 1] == 'X' &&
        (str[i + 2] == ' ' || str[i + 2] == 'O')) {
        str[i + 2] = str[i + 1];
        str[i + 1] = str[i];
        str[i] = ' ';
    }
    else {
        str[i + 1] = 'P';
        str[i] = ' ';
    }
}