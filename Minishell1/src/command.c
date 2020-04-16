/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include "minishell1.h"

char *get_home(char **env)
{
    char *str = NULL;
    int i = 0;
    int j = 5;
    int k = 0;

    while (env[i] != NULL) {
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M' &&
            env[i][3] == 'E' && env[i][4] == '=') {
            str = malloc(sizeof(char) * (my_strlen(env[i] + 5) + 2));
            while (env[i][j] != '\0')
                str[k++] = env[i][j++];
            if (str[k - 1] == '/')
                str[k - 1] = 0;
            else
                str[k] = 0;
            return (str);
        }
        i++;
    }
    return (NULL);
}

int my_exec(char **newarg, char **env)
{
    signal(SIGINT, SIG_DFL);
    if (execve(newarg[0], newarg, env) == -1) {
        my_puterr("Error: cannot exec file or command.\n");
        return (-1);
    }
    else {
        my_puterr("Error: you don't have execution rights.\n");
        return (-1);
    }
    return (0);
}

int exec_it(char **tab, char *path, char **env)
{
    char **newarg = NULL;
    int i = 0;

    newarg = malloc(sizeof(char *) * (count_tab(tab) + 1));
    while (i < count_tab(tab)){
        newarg[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
        i++;
    }
    i = 1;
    newarg[0] = my_strcpy(newarg[0], path);
    while (tab[i] != NULL) {
        newarg[i] = my_strcpy(newarg[i], tab[i]);
        i++;
    }
    newarg[i] = NULL;
    if (my_exec(newarg, env) == -1)
        return (-1);
    my_free_tab(newarg);
    return (0);
}

char    **do_command(char **path, char **tab, char **env)
{
    int i = 0;
    DIR *dirp;
    struct dirent *read;

    while (path[i] != NULL) {
        if ((dirp = opendir(path[i])) == NULL)
            return (env);
        while ((read = readdir(dirp)))
        if (my_strcmp(read->d_name, tab[0]) == 0) {
            if (path[i][my_strlen(path[i]) - 1] != '/')
                path[i] = my_strcat(path[i], "/");
            my_fork(tab, my_strcat(path[i], tab[0]), env);
            closedir(dirp);
            return (env);
        }
        if (closedir(dirp) == -1)
            return (env);
        i++;
    }
    return (env);
}

char **do_unset(char **tab, char **env)
{
    int i = 0;
    int j = -1;
    int k = 0;
    char **evt = NULL;

    if ((i = detect_pos(tab[1], env)) == -1)
        return (env);
    evt = malloc(sizeof(char *) * (count_tab(env)));
    while (env[++j]) {
        if (j == i)
            j++;
        if (j < count_tab(env)) {
            evt[k] = malloc(sizeof(char) * (my_strlen(env[j]) + 1));
            evt[k] = my_strcpy(evt[k], env[j]);
            k++;
        }
    }
    evt[k] = NULL;
    return (evt);
}