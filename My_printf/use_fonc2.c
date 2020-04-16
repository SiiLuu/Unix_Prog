/*
** EPITECH PROJECT, 2018
** use_fonc
** File description:
** tools.
*/

#include <unistd.h>
#include "printf.h"

int my_strlen(char *str)
{
    int len = 0;

    while (*str != '\0') {
        str++;
        len++;
    }
    return (len);
}

void    my_putnbr_un(unsigned int nb)
{
    if (nb >= 10) {
        my_putnbr_un(nb / 10);
        my_putnbr_un(nb % 10);
    }
    else
        my_putchar(nb + '0');
}

int my_putnbr_base(int nb, char *base)
{
    int size;

    size = my_strlen(base);
    if (nb < 0) {
    	my_putchar('-');
        nb = -nb;
    }
    if (nb == 0)
    	return (0);
    else
        my_putnbr_base(nb / size, base);
    my_putchar(base[nb % size]);
    return (0);
}