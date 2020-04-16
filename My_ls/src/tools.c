/*
** EPITECH PROJECT, 2018
** Tools
** File description:
** tools
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int a;
    a = 0;
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return 0;
}

int my_strlen(char *str)
{
    int a;
    a = 0;
    while (str[a] != '\0'){
    a++;
    }
    return (a);
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int a = 0;
    a = my_strlen(dest);

    while (src[i] != '\0') {
        dest[i + a] = src[i];
        i++;
    }
    dest[i + a] = '\0';
    return (dest);
}