/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#ifndef PRINTF_H
#define PRINTF_H

void my_printf_option(int arg, va_list ap);
void my_printf_option2(int arg, va_list ap, int count);
void my_printf_option3(int arg, va_list ap, int count);
void basic_str(char *str, int i, int j, int count);
void my_printf(char *str, ...);
void my_putchar(char c);
void my_putnbr(int nb);
void my_putnbr_un(unsigned int nb);
int my_putstr( char const *str);
int my_strlen(char *str);
int my_putnbr_base(int nb, char *base);
void my_calc_octal(int nb);
void my_putstr_octal(char *str);

#endif