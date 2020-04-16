/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** task01 day07 library
*/
#include "../../include/my.h"

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
        i = i + 1;
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
        return (0);
    else if (s1[i] > s2[i])
        return (1);
    else
        return (-1);
}