/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}