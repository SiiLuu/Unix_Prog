/*
** EPITECH PROJECT, 2018
** get_tetris_info.c
** File description:
** get info for the game
*/

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

char *get_pgame(char *s, int size)
{
    char *tetris = NULL;
    int j = 0;

    tetris = malloc(sizeof(char) * (size + 1));
    for (int i = 6; s[i] != '\0' && my_strlen(s) > 6; i++) {
        tetris[j] = s[i];
        j++;
    }
    tetris[j] = '\0';
    return (tetris);

}

tetrimino_t *get_tinfo(char *tab, tetrimino_t *tetrimino)
{
    int fd = 0;
    struct stat sb;
    char *str = malloc(sizeof(char) * my_strlen(tab) + 12);
    char *s = NULL;

    str = str_cat(str, "tetriminos/");
    str = str_cat(str, tab);
    stat(str, &sb);
    if ((fd = open(str, O_RDONLY)) == -1)
        return (NULL);
    s = malloc(sizeof(char) * (sb.st_size + 1));
    read(fd, s, sb.st_size + 1);
    tetrimino->color = (s[4] - 48);
    tetrimino->tetris = get_pgame(s, sb.st_size);
    return (tetrimino);
}

tetrimino_t *init_tetrimino(tetrimino_t *tetrimino)
{
    tetrimino->root = tetrimino;
    tetrimino->next = NULL;
    return (tetrimino);
}

tetrimino_t *add_node(tetrimino_t *tetrimino)
{
    tetrimino_t *new = malloc(sizeof(tetrimino_t));

    new->root = tetrimino->root;
    new->next = NULL;
    tetrimino->next = new;
    return (new);
}

tetrimino_t *get_tetris_info(tetrimino_t *tetrimino)
{
    int j = 0;
    DIR *dir;
    struct dirent *dirent;
    char **tab = malloc(sizeof(char *) * (count_files_nodraw() + 1));

    if ((dir = opendir("tetriminos/")) == NULL)
        return (NULL);
    while ((dirent = readdir(dir)) != NULL) {
        if (check_extrem(dirent->d_name) == 0) {
            tab[j] = get_name(dirent->d_name, '\0');
            j++;
        }
    }
    tab[j] = NULL;
    for (int k = 0; tab[k] != NULL; k++) {
        if ((tetrimino = get_tinfo(tab[k], tetrimino)) == NULL)
            return (NULL);
        if (tab[k + 1] != NULL)
            tetrimino = add_node(tetrimino);
    }
    return (tetrimino);
}