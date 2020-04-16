/*
** EPITECH PROJECT, 2018
** My ls
** File description:
** my ls
*/

#ifndef MY_LS_H
#   define MY_LS_H

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <err.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void basic_ls(char **av);
void my_putchar(char c);
int my_putstr(char *str);
void my_putnbr(int nb);
char *my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, char *src);
int my_strlen(char *str);
void blocks(char **av, struct stat fileStat);
void current_folder(char **av);
void print_right(struct stat fileStat);
void date_time(struct stat fileStat);
void infos(struct stat fileStat);
void right_gestion(char **av, DIR *midir, struct dirent *info_archivo);
void l_flag(char **av);
void ls_flagd(int ac, char **av);
void ls_flagt(char **av);

#endif