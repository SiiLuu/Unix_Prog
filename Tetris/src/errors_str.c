/*
** EPITECH PROJECT, 2018
** tools
** File description:
** tools.
*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *errors_level(char **av, int i)
{
    int j = 0;
    char *key = malloc(sizeof(char) + 5);

    for (; av[i][j] != '='; j++);
    j++;
    for (int k = 0; av[i][j] != '\0'; j++, k++) {
        if (av[i][j] > 57 || av[i][j] <= 48)
            return (NULL);
        key[k] = av[i][j];
    }
    return (key);
}

char *errors_l_flag(char **av, int i)
{
    int j = 0;

    if (av[i + 1] == NULL)
        return (NULL);
    for (; av[i + 1][j] != '\0'; j++)
        if (av[i + 1][j] > 57 || av[i + 1][j] <= 48)
            return (NULL);
    return (av[i + 1]);
}

int errors_no_args(char **av, int i)
{
    if (av[i + 1] != NULL && av[i + 1][0] != '-')
        return (84);
    return (0);
}

char *catch_key_size(char **av, int i)
{
    int b = 0;
    int j = 0;
    char *key = malloc(sizeof(char) * 8);

    for (; av[i][j] != '='; j++);
    j++;
    for (int k = 0; av[i][j] != '\0'; j++, k++) {
        if ((av[i][j] > 57 && av[i][j] != ',') ||
            (av[i][j] < 48 && av[i][j] != ','))
            return (NULL);
        (av[i][j] != ',') ? (key[k] = av[i][j]) : (key[k] = '*');
    }
    for (int a = 0; key[a] != '\0'; a++) {
        if (key[a] == '*')
            b = 1;
        if (key[a] == '*' && key[a + 1] == '\0')
            return (NULL);
    }
    if (b == 0)
        return (NULL);
    return (key);
}