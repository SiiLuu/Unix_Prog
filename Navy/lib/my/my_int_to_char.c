/*
** EPITECH PROJECT, 2019
** test
** File description:
** int to char
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

int my_strlen(char const *str)
{
    int len = 0;

    while (*str != '\0') {
        str++;
        len++;
    }
    return (len);
}

char *my_revstr(char *str)
{
    int i = 0;
    char len = 0;
    char c = 0;

    len = my_strlen(str);
    while (len / 2 != i) {
        c = str[len -(i + 1)];
        str[len - (i + 1)] = str[i];
        str[i] = c;
        i++;
    }
    return (str);
}

char *int_to_char(int num)
{
    char *str = NULL;
    int s = 0;
    int i = num;

    while (i) {
        i /= 10;
        s++;
    }
    str = malloc(sizeof(char) * s + 1);

    for (i = s; i >= 0; i--, num /= 10) {
        str[i] = num % 10 + '0';
    }
    str[s + 1] = '\0';
    my_revstr(str);
    str[s] = '\0';
    my_revstr(str);

    return (str);
}