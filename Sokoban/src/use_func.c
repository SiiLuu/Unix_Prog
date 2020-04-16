/*
** EPITECH PROJECT, 2018
** use_func
** File description:
** tools.
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my_sokoban.h"

int open_file(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return (84);
    return (fd);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *s)
{
    for (int i = 0 ; s[i] != 0 ; i++)
        my_putchar(s[i]);
}

int error_char(int ac, char *str)
{
    int i = 0;

    if (ac != 2)
        return (84);
    if (error_player(str) == 84)
        return (84);
    if (error_box(str) == 84)
        return (84);
    while (str[i] != '\0') {
        if (str[i] != '\n' && str[i] != 'P' && str[i] != '\0' &&
            str[i] != '#' && str[i] != 'X' && str[i] != 'O' && str[i] != ' ')
            return (84);
        i++;
    }
    return (0);
}

void usage_func(int ac, char **av)
{
    if ((ac == 2) && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("\t./my_sokoban map\n\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("\tmap file representing the warehouse map, ");
        my_putstr("containing '#' for walls, \n \t  'P' for the player, ");
        my_putstr("'X' for boxes and 'O' for storage locations.\n");
    }
}