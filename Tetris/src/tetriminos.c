/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"

int	check_extrem(char *d_name)
{
    int	i = 0;

    if (d_name[0] == '.' && d_name[1] == 't' && d_name[2] == 'e' &&
        d_name[3] == 't' && d_name[4] == 'r' && d_name[5] == 'i' &&
        d_name[6] == 'm' && d_name[7] == 'i' && d_name[8] == 'n' &&
        d_name[9] == 'o' && d_name[10] == '\0')
        return (1);
    while (d_name[i])
        i++;
    if (d_name[i - 1] != 'o' && d_name[i - 2] != 'n' && d_name[i - 3] != 'i'
        && d_name[i - 4] != 'm' && d_name[i - 5] != 'i' && d_name[i - 6] != 'r'
        && d_name[i - 7] != 't' && d_name[i - 8] != 'e' &&
        d_name[i - 9] != 't' && d_name[i - 10] != '.')
        return (1);
    else
        return (0);
}

char *get_name(char *d_name, char c)
{
    int i = 0;
    char *str = NULL;

    for (i = 0; d_name[i] != c; i++);
    str = malloc(sizeof(char) * (i + 1));
    for (i = 0; d_name[i] != c; i++)
        str[i] = d_name[i];
    str[i] = '\0';
    return (str);
}

void print_read(char *s)
{
    if ((s[0] <= 57 && s[0] >= 48) && (s[2] <= 57 && s[2] >= 48) &&
        (s[4] <= 57 && s[4] >= 48) && s[1] == ' ' && s[3] == ' ' &&
        s[5] == '\n' && s[6] != '\0') {
        my_putstr(" :  Size ");
        my_putchar(s[0]);
        my_putchar('*');
        my_putchar(s[2]);
        my_putstr(" :  Color ");
        my_putchar(s[4]);
        my_putstr(" :\n");
    }
    else
        my_putstr(" :  Error\n");
}

int info_tetri(char *tab)
{
    int fd = 0;
    struct stat sb;
    char *str = malloc(sizeof(char) * my_strlen(tab) + 12);
    char *s = NULL;

    str = str_cat(str, "tetriminos/");
    str = str_cat(str, tab);
    my_putstr("Tetriminos :  Name ");
    stat(str, &sb);
    if ((fd = open(str, O_RDONLY)) == -1)
        return (84);
    name(tab);
    s = malloc(sizeof(char) * (sb.st_size + 1));
    read(fd, s, sb.st_size + 1);
    print_read(s);
    for (int i = 6; s[i] != '\0' && my_strlen(s) > 6; i++)
        my_putchar(s[i]);
    close(fd);
    return (0);
}

int name_tetri(int i)
{
    int j = 0;
    char **tab = malloc(sizeof(char *) * (i + 1));
    struct dirent *dirent;
    DIR *dir;

    if ((dir = opendir("tetriminos/")) == NULL)
        return (1);
    while ((dirent = readdir(dir)) != NULL) {
        if (check_extrem(dirent->d_name) == 0) {
            tab[j] = get_name(dirent->d_name, '\0');
            j++;
        }
        tab[j] = NULL;
    }
    tab = set_alphanum_order(tab, i);
    for (int k = 0; tab[k] != NULL; k++)
        if (info_tetri(tab[k]) == 84)
            return (84);
    return (0);
}