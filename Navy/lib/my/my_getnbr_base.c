/*
** EPITECH PROJECT, 2018
** my_putnbr_modif
** File description:
** can't print a nbr < 0
*/
#include "../../include/my.h"

int check_base(char c, char *base)
{
    int i = 0;

    while (base[i] != 0) {
        if (c == base[i])
            return (i);
        i = i + 1;
    }
    return (-1);
}

unsigned int my_getnbr_base(char *str, char *base)
{
    int nb = 0;
    int i = 0;
    int tmp;

    if (my_strncmp(str, "0x", 2) == 0 && my_strcmp(base, "01") == 0)
        i = 2;
    while (str[i] != 0) {
        if ((tmp = check_base(str[i], base)) == -1)
            return (-1);
        nb = (nb + tmp) * my_strlen(base);
        i = i + 1;
    }
    nb = nb / my_strlen(base);
    return (nb);
}