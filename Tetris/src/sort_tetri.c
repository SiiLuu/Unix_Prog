/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"

char **sort_words(char **words, int count)
{
    char *x = malloc(sizeof(char) * 250);

    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
            if (my_strcmp(words[i], words[j]) < 0) {
                x = words[j];
                words[j] = words[i];
                words[i] = x;
            }
    return (words);
}