/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include <stdlib.h>
#include <stdio.h>
#include "minishell1.h"

int count_word(char *str, char limit)
{
    int i = 0;
    int j = 0;

    while (str[i] == limit)
        i++;
    if (str[i] != 0)
        j++;
    while (str[i] != 0) {
        if (str[i] == limit && str[i + 1] != limit && str[i + 1] != 0)
            j++;
        i++;
    }
    return (j);
}

char **str_to_word_tab_limited(char *str, char limit)
{
    char **tab = malloc(sizeof(char *) * (count_word(str, limit) + 1));
    int i = 0;
    int j = 0;

    while (str[0] != 0) {
        for (; str[i] != limit && str[i] != 0; i++);
        tab[j] = malloc(sizeof(char) * (i + 1));
        i = 0;
        while (str[0] != limit && str[0] != 0) {
            tab[j][i] = str[0];
            i++;
            str++;
        }
        tab[j][i] = 0;
        i = 0;
        j++;
        if (str[0] != 0)
            str++;
    }
    tab[j] = NULL;
    return (tab);
}

int count_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}

char **show_env(char **tab, char **env)
{
    int i = 0;

    if (tab[1] != NULL) {
        if (my_strcmp("-0", tab[1]) == 0) {
            while (env[i] != NULL) {
                my_putstr(env[i]);
                i++;
            }
            return (env);
        }
    }
    while (env[i] != NULL) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
    return (env);
}