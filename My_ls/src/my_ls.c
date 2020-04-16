/*
** EPITECH PROJECT, 2018
** My ls
** File description:
** my ls
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "../include/my.h"
#include <stdlib.h>

void basic_ls(char **av)
{
    DIR *dip;
    struct dirent *dit;

    if (av[1] == NULL) {
        av[1] = malloc(1);
        av[1][0] = '.';
    }
    if ((dip = opendir(av[1])) == NULL) {
        my_putstr(av[1]);
        my_putchar('\n');
        exit(0);
    }
    while ((dit = readdir(dip)) != NULL) {
        if (dit->d_name[0] != '.'){
            my_putstr(dit->d_name);
            my_putchar('\n');
        }
    }
    closedir(dip);
}

void ls_flagr(char **av)
{
    DIR *dip;
    struct dirent *dit;

    current_folder(av);
    if ((dip = opendir(av[2])) == NULL) {
        my_putstr(av[2]);
        my_putchar('\n');
        exit(0);
    }
    my_putstr(".:\n");
    while ((dit = readdir(dip)) != NULL) {
        if (dit->d_name[0] != '.') {
            my_putstr(dit->d_name);
            my_putchar(' ');
        }
    }
    my_putstr("\n\n");
    closedir(dip);
}

void ls_flagd(int ac, char **av)
{
    int i = 2;

    if (ac == 2)
        my_putstr(".\n");
    else {
        while (i < ac) {
            my_putstr(av[i]);
            my_putchar(' ');
            i++;
        }
        my_putchar('\n');
    }
}

int main(int ac, char **av)
{
    if (av[1] != NULL && av[1][0] == '-' && av[1][1] == 'l') {
        l_flag(av);
        return (0);
    }
    if (av[1] != NULL && av[1][0] == '-' && av[1][1] == 'd') {
        ls_flagd(ac, av);
        return (0);
    }
    if (av[1] != NULL && av[1][0] == '-' && av[1][1] == 't') {
        ls_flagt(av);
        return (0);
    }
    if (av[1] != NULL && av[1][0] == '-' && av[1][1] == 'R') {
        ls_flagr(av);
        return (0);
    }
    basic_ls(av);
    return (0);
}