/*
** EPITECH PROJECT, 2018
** use_fonc
** File description:
** tools.
*/

#include <unistd.h>
#include "printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int a;
    a = 0;
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return 0;
}

void    my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    else
        my_putchar(nb + '0');
}

void my_calc_octal(int nb)
{
    int tab[3];
    int i = 2;
    int res = 0;

    tab[0] = 0;
    tab[1] = 0;
    tab[2] = 0;
    while (nb > 0) {
        res = nb % 8;
        nb /= 8;
        tab[i] = res;
        i--;
    }
    my_putnbr(tab[0]);
    my_putnbr(tab[1]);
    my_putnbr(tab[2]);
}

void my_putstr_octal(char *str)
{
    int a;
    a = 0;
    while (str[a] != '\0') {
        if (str[a] < 32 || str[a] >= 127) {
            my_putchar('\\');
            my_calc_octal(str[a]);
        }
        else
            my_putchar(str[a]);
        a++;
    }
}