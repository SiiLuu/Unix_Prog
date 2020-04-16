/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell1.h"

char	**my_fork2(char **tab, char **env)
{
    int	status = 0;
    pid_t pid;

    if (access(tab[0], F_OK) == -1) {
        my_puterr("Error: file not found.\n");
        return (env);
    }
    if ((pid = fork()) == -1) {
        my_puterr("Error: fork failed.\n");
        return (env);
    }
    if (pid) {
        if (wait(&status) == -1) {
            my_puterr("Error: wait failed.\n");
            return (env);
        }
    }
    else
        if (my_exec(tab, env) == -1)
            return (env);
    return (env);
}

int	my_fork(char **tab, char *path, char **env)
{
    int	status = 0;
    pid_t pid;

    if (access(path, X_OK) == -1) {
        my_puterr("Error: no execution right.\n");
        return (-1);
    }
    if ((pid = fork()) == -1) {
        my_puterr("Error: fork failed.\n");
        return (-1);
    }
    if (pid) {
        if (wait(&status) == -1) {
            my_puterr("Error: wait failed.\n");
            return (-1);
        }
    }
    else
        if (exec_it(tab, path, env) == -1)
            return (-1);
    return (0);
}