/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

int	count_files(void)
{
    int	i = 0;
    struct dirent *dirent;
    DIR *dir;

    dir = opendir("tetriminos/");
    if (opendir("tetriminos/") == NULL)
        return (0);
    while ((dirent = readdir(dir)) != NULL)
        if (check_extrem(dirent->d_name) == 0)
            i++;
    my_putstr("Tetriminos : ");
    my_putnbr(i);
    my_putchar('\n');
    return (i);
}

void init_args(args_t *flag)
{
    flag->f_l = "^EOD";
    flag->f_r = "^EOC";
    flag->f_t = "^EOA";
    flag->f_d = "^EOB";
    flag->f_q = "q";
    flag->f_w = "Yes";
    flag->f_L = "1";
    flag->f_p = "(space)";
    flag->f_map = "20*10";
}

void print_keys(args_t *flag)
{
    my_putstr("Key Left :  ");
    my_putstr(flag->f_l);
    my_putstr("\nKey Right :  ");
    my_putstr(flag->f_r);
    my_putstr("\nKey Turn :  ");
    my_putstr(flag->f_t);
    my_putstr("\nKey Drop :  ");
    my_putstr(flag->f_d);
    my_putstr("\nKey Quit :  ");
    my_putstr(flag->f_q);
    my_putstr("\nKey Pause :  ");
    my_putstr(flag->f_p);
    my_putstr("\nNext :  ");
    my_putstr(flag->f_w);
    my_putstr("\nLevel :  ");
    my_putstr(flag->f_L);
    my_putstr("\nSize :  ");
    my_putstr(flag->f_map);
    my_putstr("\n");
}

void name(char *tab)
{
    for (int i = 0; tab[i] != '\0'; i++) {
        if (tab[i] == '.' && tab[i + 1] == 't' && tab[i + 2] == 'e'
            && tab[i + 3] == 't' && tab[i + 4] == 'r' &&
            tab[i + 5] == 'i' && tab[i + 6] == 'm' &&
            tab[i + 7] == 'i' && tab[i + 8] == 'n' &&
            tab[i + 9] == 'o' && tab[i + 10] == '\0')
            break;
        my_putchar(tab[i]);
    }
}

int print_debug(args_t *flag)
{
    int i = 0;

    my_putstr("*** DEBUG MODE ***\n");
    print_keys(flag);
    if ((i = count_files()) == 0)
        return (84);
    if (name_tetri(i) == 1)
        return (84);
    return (0);
}