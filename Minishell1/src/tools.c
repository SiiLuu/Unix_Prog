/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include "minishell1.h"

char *my_strcat(char *dest, char *src)
{
    int i = my_strlen(dest);
    int j = 0;

    while (src[j]) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
        i++;
    }
    if (s1[i] < s2[i])
        return (-1);
    if (s1[i] > s2[i])
        return (1);
    return (0);
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}