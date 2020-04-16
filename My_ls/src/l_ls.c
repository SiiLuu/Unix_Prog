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
#include <err.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void current_folder(char **av)
{
    if (av[2] == NULL) {
        av[2] = malloc(1);
        av[2][0] = '.';
    }
}

void blocks(char **av, struct stat fileStat)
{
    struct dirent *read;
    DIR *mdir;
    int result = 0;
    char fullpath[256];

    current_folder(av);
    mdir = opendir(av[2]);
    while ((read = readdir(mdir)) != NULL) {
        if (read->d_name[0] != '.') {
            my_strcpy(fullpath, av[2]);
            my_strcat(fullpath, "/");
            my_strcat(fullpath, read->d_name);
            stat(fullpath, &fileStat);
            result = result + fileStat.st_blocks;
        }
    }
    result = result / 2;
    my_putstr("total ");
    my_putnbr(result);
    my_putchar('\n');
    closedir(mdir);
}

void ls_flagt(char **av)
{
    DIR *dip;
    struct dirent *dit;

    current_folder(av);
    if ((dip = opendir(av[2])) == NULL) {
        my_putstr(av[2]);
        my_putchar('\n');
        exit(0);
    }
    while ((dit = readdir(dip)) != NULL) {
        if (dit->d_name[0] != '.') {
            my_putstr(dit->d_name);
            my_putstr("\n");
        }
    }
    closedir(dip);
}