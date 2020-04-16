/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include <stdlib.h>
#include "minishell1.h"

char *get_pwd(char **env)
{
    char *pwd = NULL;
    int i = 0;

    while (env[i] != NULL) {
        if (env[i][0] == 'P' && env[i][1] == 'W' &&
            env[i][2] == 'D' && env[i][3] == '=') {
            pwd = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
            pwd = my_strcpy(pwd, env[i]);
            if (pwd[my_strlen(pwd) - 1] != '/')
                pwd = my_strcat(pwd, "/");
            return (pwd);
        }
        i++;
    }
    return (NULL);
}

int	calc_len(char *s)
{
    int i = 0;

    while (s[i] != '/' && s[i] != '\0')
        i++;
    return (i);
}

char *cpy_pwd(char *s, char *pwd, char *home)
{
    int i = 0;
    int j = 0;
    char *s2 = NULL;
    char *env2 = NULL;

    while (i < my_strlen(s)) {
        j = 0;
        s2 = malloc(sizeof(char) * (calc_len(s + i) + 1));
        while (s[i] != '/' && s[i])
            s2[j++] = s[i++];
        s2[j] = '\0';
        if (my_strcmp(s2, "..") == 0)
            pwd = write_prec(pwd);
        if (s[i] == '/' && i == 0)
            pwd = write_all("/", pwd);
        if (my_strcmp(s, ".") != 0)
            pwd = write_next(s2, pwd);
        i++;
    }
    env2 = malloc(sizeof(char) * (my_strlen(pwd) + 5));
    return ((env2 = my_strcpy(env2, pwd)));
}

char **parse_replace_in_env(char *s, char **env)
{
    int i = 0;
    char **env2 = NULL;
    char *pwd = NULL;

    pwd = get_pwd(env);
    if (pwd == NULL || my_strcmp(s, ".") == 0)
        return (env);
    env2 = malloc(sizeof(char *) * (count_tab(env) + 2));
    while (env[i] != NULL) {
        if (i == detect_pos("PWD", env))
            env2[i] = cpy_pwd(s, pwd, get_home(env));
        else {
            env2[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
            env2[i] = my_strcpy(env2[i], env[i]);
        }
        i++;
    }
    env2[i] = NULL;
    return (env2);
}