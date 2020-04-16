/*
** EPITECH PROJECT, 2018
** my_putnbr_base
** File description:
** function that converts and displays a decimal number
*/
#include "../../include/my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int len_base = my_strlen(base);

    if (nbr < 0) {
        nbr = nbr * (-1);
        my_putchar('-');
    }
    if (nbr / len_base)
        my_putnbr_base(nbr / len_base, base);
    my_putchar(base[nbr % len_base]);
    return (0);
}