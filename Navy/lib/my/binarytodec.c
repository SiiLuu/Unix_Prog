/*
** EPITECH PROJECT, 2018
** getnbr
** File description:
** convert a char to int
*/

#include "../../include/my.h"

int my_compute_power_it(int nb, int p)
{
    int res = 1;

    if (p == 0) {
        return (1);
    }
    else if (p < 0 ) {
        return (0);
    }
    else if (res >= 2147483647) {
        return (0);
    }
    for (int i = 0; i < p; i++) {
        res *= nb;
    }
    return (res);
}

int binary_decimal(int n)
{
    int decimal = 0;
    int i = 0;
    int rem = 0;

    while (n != 0) {
        rem = n % 10;
        n /= 10;
        decimal += rem * my_compute_power_it(2, i);
        ++i;
    }
    return (decimal);
}