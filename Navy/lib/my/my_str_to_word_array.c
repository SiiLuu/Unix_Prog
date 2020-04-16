/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** put a string in array betwen space
*/
#include "../../include/my.h"

int my_count_space(char *str)
{
    int i = 0;
    int space = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            space++;
        i++;
    }
    if (str[0] == ' ')
        space -= 1;
    space += 1;

    return (space);
}

int my_len_word(char *str)
{
    static int i = 0;

    while (str[i] && str[i] != ' ') {
        i += 1;
    }
    while (str[i] && str[i] == ' ')
        i += 1;
    return (i);
}

char **my_put_in_str(char *str, char **new_str, int k, int space)
{
    static int i = 0;
    int j = 0;

    new_str[k] = malloc(sizeof(char) * my_len_word(str));
    if (str[0] == ' ') {
        while (str[i] == ' ') {
            i++;
        }
    }
    while (str[i] != '\n') {
        new_str[k][j] = str[i];
        i++;
        j++;
    }
    while (str[i] == '\n')
        i += 1;
    if (k + 1 == space)
        i = 0;
    new_str[k][j] = '\n';
    return (new_str);
}

char **my_str_to_word_array(char *str)
{
    char **new_str = NULL;
    int space = my_count_space(str);
    int k = 0;

    new_str = malloc(sizeof(char *) * 10);
    while (k != space) {
        new_str = my_put_in_str(str, new_str, k, space);
        k++;
    }
    return (new_str);
}