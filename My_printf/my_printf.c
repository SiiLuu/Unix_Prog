/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** .
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "printf.h"

void basic_str(char *str, int i, int j, int count)
{
    if (str[i - 1] != '%' && str[i - j] != '%') {
        my_putchar(str[i]);
        count++;
    }
    if (str[i - 1] == '%' && str[i] == '\n')
        my_putchar('\n');
}

void my_printf(char *str, ...)
{
    int j = 1;
    int arg = 0;
    va_list ap;
    int count = 0;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            i++;
            if (str[i] == ' ') {
                for (; str[i] == ' '; i++)
                    j++;
                my_putchar(' ');
            }
            arg = str[i];
            my_printf_option3(arg, ap, count);
        }
        basic_str(str, i, j, count);
    }
    va_end(ap);
}