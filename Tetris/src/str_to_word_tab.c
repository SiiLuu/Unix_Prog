/*
** EPITECH PROJECT, 2018
** str
** File description:
** to word tab
*/

#include <stdlib.h>
#include "my.h"

char **set_alphanum_order(char **tab, int count)
{
    int i = 0;
    int j = 0;
    char *temp = malloc(sizeof(char) * 25);

    for (i = 0; i < count; i++)
        for (j = i + 1; j < count; j++)
            if (my_strcmp(tab[i], tab[j]) > 0) {
                temp = str_copy(tab[i], temp);
                tab[i] = str_copy(tab[j], tab[i]);
                tab[j] = str_copy(temp, tab[j]);
            }
    return (tab);
}