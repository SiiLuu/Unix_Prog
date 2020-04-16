/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** navy project
*/

#include "my.h"

int global = 0;

void check_letters(char **cord, int k, output_t *output)
{
    if ((cord[k][3] - 48) + (cord[k][0] - 49) != (cord[k][6] - 48))
        output->return_status = 84;
}

void check_letters_2(char **cord, int k, output_t *output)
{
    if ((cord[k][2] - 48) + (cord[k][0] - 49) != (cord[k][5]) - 48)
        output->return_status = 84;
}

int loop_game(char **av, int ac, output_t *output)
{
    int j = 0;

    while (1) {
        if (output->status_open == 84 || output->return_status == 84 ||
            output->eof == 84)
            return (84);
        if (j == 0)
            chose_player(ac, av, output);
        if (j > 0)
            next_round(output, ac);
        j++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int a = 10;
    int i = 0;
    output_t *output = malloc(sizeof(output_t));

    if (ac < 2 || ac > 3)
        return (84);
    else if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h' &&
        av[1][2] == '\0'))
        help_func();
    else {
        i = loop_game(av, ac, output);
        if (i == 1)
            return (0);
        if (i == 84)
            return (0);
    }
    return (1);
}