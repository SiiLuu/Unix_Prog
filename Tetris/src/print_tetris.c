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

void print_tetris3(void)
{
    start_color();
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(5));
    mvprintw(0, 23, " * \n");
    mvprintw(1, 23, " * \n");
    mvprintw(2, 23, " * \n");
    mvprintw(3, 23, " * \n");
    mvprintw(4, 23, " * \n");
    attroff(COLOR_PAIR(5));
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(6));
    mvprintw(0, 26, "* * *");
    mvprintw(1, 26, "*    ");
    mvprintw(2, 26, "* * *");
    mvprintw(3, 26, "    *");
    mvprintw(4, 26, "* * *");
    attroff(COLOR_PAIR(6));
}

void print_tetris2(void)
{
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvprintw(0, 12, "* * *\n");
    mvprintw(1, 12, "  *  \n");
    mvprintw(2, 12, "  *  \n");
    mvprintw(3, 12, "  *  \n");
    mvprintw(4, 12, "  *  \n");
    attroff(COLOR_PAIR(1));
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    mvprintw(0, 18, "* * *");
    mvprintw(1, 18, "*   *");
    mvprintw(2, 18, "* *  ");
    mvprintw(3, 18, "*  * ");
    mvprintw(4, 18, "*   *");
    attroff(COLOR_PAIR(2));
}

void print_tetris(void)
{
    start_color();
    init_pair(3, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    mvprintw(0, 0, "* * *\n");
    mvprintw(1, 0, "  *  \n");
    mvprintw(2, 0, "  *  \n");
    mvprintw(3, 0, "  *  \n");
    mvprintw(4, 0, "  *  \n");
    attroff(COLOR_PAIR(3));
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    mvprintw(0, 6, "* * *");
    mvprintw(1, 6, "*    ");
    mvprintw(2, 6, "* *  ");
    mvprintw(3, 6, "*    ");
    mvprintw(4, 6, "* * *");
    attroff(COLOR_PAIR(4));
    print_tetris2();
    print_tetris3();
}