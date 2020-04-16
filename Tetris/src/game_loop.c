/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

int check_size(args_t *flag)
{
    char *string = "Please enlarge the size of the terminal.";

    if (LINES < flag->nb1 + 2) {
        clear();
        mvprintw(LINES / 2, (COLS / 2) - 20, string);
        return (1);
    }
    else if (COLS < (45 + flag->nb1)) {
        clear();
        mvprintw(LINES / 2, (COLS / 2) - 20, string);
        return (1);
    }
    else
        return (0);
}

void game_loop(args_t *flag)
{
    char *string = "                                        ";

    while (1)  {
        if (check_size(flag) == 1)
            check_size(flag);
        else {
            mvprintw(LINES / 2, (COLS / 2) - 20, string);
            print_tetris();
            print_stats(flag);
            print_game_tab(flag);
        }
        refresh();
    }
}

int my_popup(char **av, args_t *flag)
{
    tetrimino_t *tetrimino = malloc(sizeof(tetrimino_t));

    tetrimino = init_tetrimino(tetrimino);
    tetrimino = get_tetris_info(tetrimino);
    if (tetrimino == NULL)
        return (84);
    for (int i = 0; av[i] != NULL; i++) {
        if (!my_strcmp(av[i], "-D") || !my_strcmp(av[i], "--debug")) {
            if (print_debug(flag) == 84)
                return (84);
            my_putstr("Press any key to start Tetris");
            read(0, "", 1);
        }
    }
    keypad(stdscr, TRUE);
    initscr();
    game_loop(flag);
    endwin();
    return (0);
}