/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include <stdlib.h>
#include "minishell1.h"

int last_name(char *s)
{
    int len = -1;
    int nb = 0;

    len = my_strlen(s);
    while (s[len] != '/') {
        nb++;
        len--;
    }
    return (nb + 1);
}

char *write_all(char *s, char *pwd)
{
    char *env2 = NULL;
    int len = -1;

    env2 = malloc(sizeof(char) * (my_strlen(pwd) + 1));
    env2 = my_strcpy(env2, pwd);
    len = my_strlen(env2);
    while (env2[len] != '=') {
        env2[len] = 0;
        len--;
    }
    env2 = my_strcat(env2, s);
    return (env2);
}

char *write_prec(char *env)
{
    char *env2 = NULL;
    int len = 0;

    len = my_strlen(env);
    env2 = malloc(sizeof(char) * (my_strlen(env) + 1));
    env2 = my_strcpy(env2, env);
    if (env2[len - 1] == '/' && env[len - 2] != '=') {
        env2[len] = 0;
        len--;
    }
    len--;
    while (env2[len] != '/') {
        env2[len] = 0;
        len--;
    }
    return (env2);
}

char *write_next(char *s, char *pwd)
{
    char *env2 = NULL;

    env2 = malloc(sizeof(char) * (my_strlen(pwd) + my_strlen(s) + 2));
    env2 = my_strcpy(env2, pwd);
    env2 = my_strcat(env2, s);
    env2 = my_strcat(env2, "/");
    return (env2);
}