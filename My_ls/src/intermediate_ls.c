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

void print_right(struct stat fileStat)
{
    my_putstr((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    my_putstr((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((fileStat.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((fileStat.st_mode & S_IXOTH) ? "x" : "-");
}

void date_time(struct stat fileStat)
{
    char *str  = NULL;
    char *result = NULL;
    int i = 0;
    int j = 4;

    result = malloc(sizeof(char) * 14);
    str = ctime(&fileStat.st_mtime);
    str[16] = '\0';
    while (str[i] != '\0') {
        result[i] = str[j];
        i++;
        j++;
    }
    my_putstr(result);
}

void infos(struct stat fileStat)
{
    my_putnbr(fileStat.st_nlink);
    my_putchar(' ');
    my_putstr(getpwuid(fileStat.st_uid)->pw_name);
    my_putchar(' ');
    my_putstr(getgrgid(fileStat.st_gid)->gr_name);
    my_putchar(' ');
    my_putnbr(fileStat.st_size);
    my_putchar(' ');
    date_time(fileStat);
}

void right_gestion(char **av, DIR *midir, struct dirent *info_archivo)
{
    char fullpath[256];
    struct stat fileStat;

    while ((info_archivo = readdir(midir)) != 0) {
        my_strcpy(fullpath, av[2]);
        my_strcat(fullpath, "/");
        my_strcat(fullpath, info_archivo->d_name);
        if (!stat(fullpath, &fileStat) && info_archivo->d_name[0] != '.') {
            print_right(fileStat);
            my_putstr(". ");
            infos(fileStat);
            my_putchar(' ');
            my_putstr(info_archivo->d_name);
            my_putchar('\n');
        }
    }
}

void l_flag(char **av)
{
    DIR *midir;
    struct stat fileStat;
    struct dirent *info_archivo = NULL;

    current_folder(av);
    blocks(av, fileStat);
    if ((midir = opendir(av[2])) == NULL) {
        perror("Error in opendir");
    }
    right_gestion(av, midir, info_archivo);
    closedir(midir);
}