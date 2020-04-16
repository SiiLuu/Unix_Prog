/*
** EPITECH PROJECT, 2018
** win_lose
** File description:
** detect win and loose.
*/

#include <stdlib.h>
#include <ncurses.h>
#include "../include/my_sokoban.h"

int check_win(char *str)
{
    int   i = 0;

    while (str[i] != '\0') {
        if (str[i] == 'O')
            return (1);
        i++;
    }
    return (0);
}

int check_loose(char *str, int i)
{
    int distance = 0;

    distance = calc_distance_x(str);
    if ((str[i - 1] == '#' && str[i + distance + 1] == '#') ||
        (str[i + 1] == '#' && str[i + distance + 1] == '#') ||
        (str[i + 1] == ' ' && str[i + distance + 1] == '#'
            && str[i + 2] == '\n') ||
        (str[i + 1] == ' ' && str[i - distance - 1] == '#'
            && str[i + 2] == '\n') ||
        (str[i - distance - 1] == '#' && str[i + 1] == '#') ||
        (str[i - distance - 1] == '#' && str[i - 1] == '#'))
        return (1);
    return (0);
}

int loose(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0')
    {
        if (str[i] == 'X') {
            j = check_loose(str, i);
            if (j != 1)
                return (0);
        }
        i++;
    }
    endwin();
    exit(1);
}

void check_status(char *str)
{
    loose(str);
    if (check_win(str) == 0) {
        endwin();
        exit(0);
    }
}