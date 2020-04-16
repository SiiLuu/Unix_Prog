/*
** EPITECH PROJECT, 2018
** use_func
** File description:
** tools.
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *s)
{
    for (int i = 0 ; s[i] != 0 ; i++)
        my_putchar(s[i]);
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

int my_strcmp_limited(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '=') {
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

char *str_cat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    int ldest = my_strlen(dest);
    int lsrc = my_strlen(src);
    char *new = malloc(sizeof(char) * (ldest + lsrc + 1));

    for (i = 0; i != ldest; i++)
        new[i] = dest[i];
    for (j = 0; j != lsrc; j++)
        new[i + j] = src[j];
    new[i + j] = '\0';
    return (new);
}