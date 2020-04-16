/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** .
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "printf.h"

void my_printf_option(int arg, va_list ap)
{
    switch(arg) {
        case 'i':
        case 'd':
            my_putnbr(va_arg(ap, int));
            break;
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'X':
            my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
            break;
        case 'x':
            my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
            break;
        case 'o':
            my_putnbr_base(va_arg(ap, int), "01234567");
            break;
    }
}

void my_printf_option2(int arg, va_list ap, int count)
{
    switch(arg) {
        case 'S':
            my_putstr_octal(va_arg(ap, char*));
            break;
        case 'n':
            my_putnbr(count);
            break;
    }
    my_printf_option(arg, ap);
}

void my_printf_option3(int arg, va_list ap, int count)
{
    switch(arg) {
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 'u':
            my_putnbr_un(va_arg(ap, unsigned int));
            break;
        case '%':
            my_putchar('%');
            break;
        case 'b':
            my_putnbr_base(va_arg(ap, int), "01");
            break;
        case 'p':
            my_putstr("0x");
            my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
            break;
    }
    my_printf_option2(arg, ap, count);
}