/*
** EPITECH PROJECT, 2018
** my_putstr_modif.c
** File description:
** putstr who print in maj
*/
#include "../../include/my.h"

int my_putstr_modified(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ')
            my_putchar(str[i] - 32);

        else
            my_putchar(str[i]);
        i++;
    }
}