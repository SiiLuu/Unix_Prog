/*
** EPITECH PROJECT, 2018
** getnbr
** File description:
** convert a char to int
*/
#include "../../include/my.h"

int my_getnbr(char *str)
{
    int nb = 0;
    int neg = 0;
    int i = 0;

    while (str[i] < 0) {
        neg = 1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] == '\n')
            return (nb);
        nb = nb * 10 + str[i] - 48;
        i++;
    }
    if (neg == 1)
        nb = -nb;
    return (nb);
}