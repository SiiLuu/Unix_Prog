/*
** EPITECH PROJECT, 2018
** my_putnbr_modif
** File description:
** can't print a nbr < 0
*/
#include "../../include/my.h"

int my_putnbr_base_modified(int nbr, char const *base)
{
    int len_base = my_strlen(base);
    char *i = "11111111111111111111111111111111";

    if (nbr < 0) {
        my_putstr(i);
        return (0);
    }
    if (nbr / len_base)
        my_putnbr_base_modified(nbr / len_base, base);
    my_putnbr(nbr % len_base);
    return (0);
}