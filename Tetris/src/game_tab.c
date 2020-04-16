/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include <ncurses.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

void print_next_prev(void)
{
    mvprintw(5, 36, "/-next-------\\");
    mvprintw(6, 36, "|            |");
    mvprintw(7, 36, "|            |");
    mvprintw(8, 36, "|            |");
    mvprintw(9, 36, "|            |");
    mvprintw(10, 36, "|            |");
    mvprintw(11, 36, "|            |");
    mvprintw(12, 36, "\\------------/\n");
    attron(COLOR_PAIR(5));
    mvprintw(8, 42, "**");
    mvprintw(9, 42, "**");
    attroff(COLOR_PAIR(5));
}

void print_midl_tab(args_t *flag, int x, int y)
{
    flag->n1 = get_first_numbers(flag);
    flag->n2 = get_second_numbers(flag);
    flag->nb1 = my_getnbr(flag->n1);
    flag->nb2 = my_getnbr(flag->n2);
    while (x < (flag->nb2 + 53)) {
        mvprintw(y, (x + 1), "-");
        mvprintw(y + flag->nb1 + 1, (x + 1), "-");
        x++;
    }
    x = 53;
    while (y < flag->nb1 + 1) {
        mvprintw(y + 1, x, "|");
        mvprintw(y + 1, x + flag->nb2 + 1, "|");
        y++;
    }
}

void print_game_tab(args_t *flag)
{
    int x = 53;
    int y = 0;

    if (!(my_strcmp(flag->f_w, "Yes")))
        print_next_prev();
    attron(COLOR_PAIR(4));
    mvprintw(1, 57, " * *");
    mvprintw(2, 57, "* * *");
    mvprintw(3, 57, " * *");
    mvprintw(4, 57, "  *");
    attroff(COLOR_PAIR(4));
    mvprintw(y, x, "+");
    mvprintw(y, x + flag->nb2 + 1, "+");
    print_midl_tab(flag, x, y);
    mvprintw(y + flag->nb1 + 1, x, "+");
    mvprintw(y + flag->nb1 + 1, x + flag->nb2 + 1, "+");
}