/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell1.h"

char *get_path(char **env)
{
    int	i = 0;
    int	j = 5;
    int	k = 0;
    char *path = NULL;

    while (env[i] != NULL) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
            env[i][3] == 'H' && env[i][4] == '=') {
            path = malloc(sizeof(char) * (my_strlen(env[i] + 5) + 1));
            while (env[i][j] != '\0') {
                path[k] = env[i][j];
                k++;
                j++;
            }
            path[k] = '\0';
            return (path);
        }
        i++;
    }
    return (NULL);
}

char *get_next_line(const int fd)
{
    static char buff[1 + 1];
    char *line = NULL;
    int ret = 0;
    int j = 0;

    buff[0] = '\0';
    if ((ret = read(fd, buff, 32000)) == -1)
        return (NULL);
    if (buff[0] == '\0')
        return (NULL);
    line = malloc(sizeof(char) * (ret + 1));
    while (buff[j] != '\n' && buff[j] != '\0') {
        line[j] = buff[j];
        j++;
    }
    line[j] = '\0';
    return (line);
}