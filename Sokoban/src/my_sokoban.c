/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** game sokoban.
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my_sokoban.h"

int check_size(char *str)
{
    int i = calc_distance_x(str);
    int j = calc_distance_y(str);
    char *string = "Please enlarge the size of the terminal.";

    if (LINES < i) {
        mvprintw(LINES / 2, (COLS / 2) - 20, string);
        return (2);
    }
    else if (COLS < j) {
        mvprintw(LINES / 2, (COLS / 2) - 20, string);
        return (1);
    }
    else
        return (0);
}

void keys(char *str, int ch)
{
    if (ch == KEY_LEFT)
        move_left(str);
    if (ch == KEY_RIGHT)
        move_right(str);
    if (ch == KEY_DOWN)
        move_down(str);
    if (ch == KEY_UP)
        move_up(str);
}

void my_popup(char *str)
{
    int ch = 0;

    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        check_status(str);
    	if (check_size(str) == 1 || check_size(str) == 2)
    	   check_size(str);
        else
            printw(str);
        ch = getch();
        clear();
        keys(str, ch);
        refresh();
    }
    endwin();
}

int main(int ac, char **av)
{
    int fd = 0;
    int size = 1;
    char *buff;
    struct stat filepath;

    usage_func(ac, av);
    stat(av[1], &filepath);
    buff = malloc(sizeof(char *) * filepath.st_size);
    fd = open_file(av[1]);
    size = read(fd, buff, filepath.st_size);
    if (error_char(ac, buff) == 84)
        return (84);
    my_popup(buff);

    close(fd);
    return (0);
}