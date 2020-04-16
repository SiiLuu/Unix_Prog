/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell1.h"

int my_free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
    return (0);
}

char **get_command(char **tab, char **path, char **env)
{
    char **env_cp = NULL;

    if (my_strcmp(tab[0], "setenv") == 0)
        env_cp = do_setenv(tab, env);
    if (my_strcmp(tab[0], "unsetenv") == 0)
        env_cp = do_unset(tab, env);
    if ((tab[0][0] == '.' && tab[0][1] == '/') || tab[0][0] == '/')
        env_cp = my_fork2(tab, env);
    if (my_strcmp(tab[0], "env") == 0)
        env_cp = show_env(tab, env);
    if (path != NULL && my_strcmp(tab[0], "env") != 0 &&
        my_strcmp(tab[0], "setenv") != 0 &&
        my_strcmp(tab[0], "unsetenv") != 0)
        env_cp = do_command(path, tab, env);
    return (env_cp);
}

char **cpy_env(char **env)
{
    char **env_cp = NULL;
    int i = 0;

    env_cp = malloc(sizeof(char *) * (count_tab(env) + 1));
    while (env[i]) {
        env_cp[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        env_cp[i] = my_strcpy(env_cp[i], env[i]);
        i++;
    }
    env_cp[i] = NULL;
    return (env_cp);
}

void body_code(char **env)
{
    char **tab = NULL;
    char **env_cp = NULL;
    char **path = NULL;
    char *s = NULL;

    env_cp = cpy_env(env);
    while (1) {
        if ((s = get_next_line(0)) == NULL)
            exit(0);
        if (s[0] > 32 && s[0] < 127) {
            if (get_path(env_cp) != NULL)
                path = str_to_word_tab_limited(get_path(env_cp), ':');
            tab = str_to_word_tab_limited(s, ' ');
            if (my_strcmp(s, "exit") == 0)
                exit(0);
            env_cp = get_command(tab, path, env_cp);
            if (path != NULL)
                my_free_tab(path);
        }
        my_putstr("my_prompt ~ >");
    }
}