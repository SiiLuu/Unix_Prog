/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include <ncurses.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *str_copy(char *s1, char *s2)
{
    int i = 0;

    s2 = malloc(sizeof(char) * (my_strlen(s1) + 1));
    while (s1[i] != '\0') {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

void print_stats(args_t *flag)
{
    clock_t timer = clock();
    int a = (timer / 1000000) % 60;
    int b = (timer / (1000000 * 60));

    mvprintw(6, 0, "/------------------------------\\");
    mvprintw(7, 0, "|                              |");
    mvprintw(8, 0, "| Hight Score                  |");
    mvprintw(9, 0, "| Score                        |");
    mvprintw(10, 0, "|                              |");
    mvprintw(11, 0, "| Lines                        |");
    mvprintw(12, 0, "| Level                        |");
    mvprintw(13, 0, "|                              |");
    mvprintw(14, 0, "| Timer                        |");
    mvprintw(15, 0, "\\------------------------------/");
    mvprintw(12, 27, flag->f_L);
    mvprintw(8, 24, "0000");
    mvprintw(9, 24, "0000");
    mvprintw(11, 24, "0000");
    mvprintw(14, 25, "%d:%d", b, a);
}