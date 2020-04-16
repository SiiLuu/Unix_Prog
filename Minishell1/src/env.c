/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell1.h"

char **write_in_new(char **tab, char **env)
{
    char **envp = NULL;
    int   i = 0;

    if (detect_pos(tab[1], env) != -1)
        return (env);
    envp = malloc(sizeof(char *) * (count_tab(env) + 3));
    while (i < count_tab(env)) {
        envp[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        i++;
    }
    i = -1;
    while (env[++i] != NULL)
        envp[i] = my_strcpy(envp[i], env[i]);
    envp[i] = malloc(sizeof(char) * (my_strlen(tab[1]) + my_strlen(tab[2]) +2));
    envp[i] = my_strcpy(envp[i], tab[1]);
    envp[i] = my_strcat(envp[i], "=");
    envp[i] = my_strcat(envp[i], tab[2]);
    envp[i + 1] = NULL;
    my_free_tab(env);
    return (envp);
}

int detect_pos(char *s, char **env)
{
    char *tmp = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    while (env[i] != NULL) {
        j = 0;
        k = 0;
        while (env[i][j] != '=')
            j++;
        tmp = malloc(sizeof(char) * (j + 1));
        j = 0;
        while (env[i][j] != '=')
            tmp[k++] = env[i][j++];
        tmp[k] = 0;
        if (my_strcmp(s, tmp) == 0)
            return (i);
        free(tmp);
        i++;
    }
    return (-1);
}

char *cpy_line(char *evt, char **tab)
{
    evt = my_strcpy(evt, tab[1]);
    evt = my_strcat(evt, "=");
    evt = my_strcat(evt, tab[2]);
    return (evt);
}

char **replace_in_new(char **tab, char **env)
{
    char **evt = NULL;
    int   i = 0;

    evt = malloc(sizeof(char *) * (count_tab(env) + 1));
    while (env[i] != NULL) {
        if (i == detect_pos(tab[1], env)) {
            evt[i] = malloc(sizeof(char) *
                (my_strlen(tab[1]) + my_strlen(tab[2]) + 2));
            evt[i] = cpy_line(evt[i], tab);
        }
        else {
            evt[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
            evt[i] = my_strcpy(evt[i], env[i]);
        }
        i++;
    }
    evt[i] = NULL;
    return (evt);
}

char **do_setenv(char **tab, char **env)
{
    char **envp = NULL;

    if (count_tab(tab) != 3) {
        my_puterr("Usage: setenv key value\n");
        return (env);
    }
    if (my_strcmp(tab[2], "0") != 0) {
        envp = write_in_new(tab, env);
        return (envp);
    }
    else if (my_strcmp(tab[2], "1") != 0) {
        envp = replace_in_new(tab, env);
        return (envp);
    }
    else
        return (env);
    return (env);
}