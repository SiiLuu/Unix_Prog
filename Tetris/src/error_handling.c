/*
** EPITECH PROJECT, 2018
** tools
** File description:
** tools.
*/

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

char *get_first_numbers(args_t *flag)
{
    int i = 0;
    char *n1 = NULL;

    for (i = 0; flag->f_map[i] != ',' && flag->f_map[i] != '*'; i++);
    n1 = malloc(sizeof(char) * (i + 1));
    for (i = 0; flag->f_map[i] != ',' && flag->f_map[i] != '*'; i++)
        n1[i] = flag->f_map[i];
    n1[i] = '\0';
    return (n1);
}

char *get_second_numbers(args_t *flag)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char *n2 = NULL;

    for (i = 0; flag->f_map[i] != ',' && flag->f_map[i] != '*'; i++);
    i++;
    for (; flag->f_map[i] != '\0'; i++)
        j++;
    n2 = malloc(sizeof(char) * (j + 1));
    for (i = 0; flag->f_map[i] != ',' && flag->f_map[i] != '*'; i++);
    i++;
    for (; flag->f_map[i] != '\0'; i++) {
        n2[count] = flag->f_map[i];
        count++;
    }
    n2[count] = '\0';
    return (n2);
}

int my_getnbr(char *nb)
{
    int temp = 0;
    int sign = 1;

    while (nb[0] == '-') {
        sign = sign * -1;
        nb = nb + 1;
    }
    while (*nb != '\0') {
        if (*nb < '0' || *nb > '9')
            break;
        temp = temp * 10 + (*nb - 48);
        nb = nb + 1;
    }
    temp = temp * sign;
    return (temp);
}

int error_handling(int ac, char **av)
{
    if (ac == 2 && av[1][0] != '-')
        return (84);
    for (int i = 0; av[i] != NULL; i++)
        if (av[i][0] == '-' && av[i][1] != '-' && av[i][2] != '\0')
            return (84);
    return (0);
}

int	count_files_nodraw(void)
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
    return (i);
}