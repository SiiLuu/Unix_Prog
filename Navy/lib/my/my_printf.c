/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** copy of print f, fonction that print every fonctions
*/
#include "../../include/my.h"

int basic_flags(char *str, va_list ap, int i)
{
    int d;
    char c;
    char *s;

    switch (str[i + 1]) {
        case 'd': case 'i':
            d = va_arg(ap, int);
            my_putnbr(d);
            break;
        case 's':
            s = va_arg(ap, char *);
            my_putstr(s);
            break;
        case 'c':
            c = va_arg(ap, int);
            my_putchar(c);
            break;
    }
    return (0);
}

int flags2(char *str, va_list ap, int i)
{
    int o;
    int x;
    int X;
    unsigned int u;

    switch (str[i + 1]) {
        case 'o':
            o = va_arg(ap, int);
            my_putnbr_base(o, "01234567");
            break;
        case 'x':
            x = va_arg(ap, int);
            my_putnbr_base(x, "0123456789abcdef");
            break;
        case 'X':
            X = va_arg(ap, int);
            my_putnbr_base(X, "0123456789ABCDEF");
            break;
    }
    return (0);
}

int flags3(char *str, va_list ap, int i)
{
    char *S;
    int p;
    int u;

    switch (str[i + 1]) {
        case 'S':
            S = va_arg(ap, char *);
            my_putstr_modified(S);
            break;
        case  '%':
            p = va_arg(ap, int);
            my_putnbr(p);
            my_putchar('%');
            break;
    }
    return (0);
}

int my_printf(char *str, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, str);
    while (str[i] != '\0') {
        if (str[i] == 37) {
            basic_flags(str, ap, i);
            flags2(str, ap, i);
            flags3(str, ap, i);
        i = i + 1;
        }
        else if (str[i] != 37)
            my_putchar(str[i]);
    i++;
    }
    va_end(ap);
    return (0);
}