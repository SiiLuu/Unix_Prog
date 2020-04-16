/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include <stdlib.h>
#include <ncurses.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

int term(char **env, args_t *flag)
{
    int i = 0;

    for (; my_strcmp_limited(env[i], "TERM="); i++);
    if (env[i][5] == 'v' && env[i][6] == 't') {
        flag->f_l = "^E[D";
        flag->f_r = "^E[C";
        flag->f_t = "^E[A";
        flag->f_d = "^E[B";
        return (84);
    }
    if (env[i][5] != 'x')
        return (84);
    return (0);
}

int main(int ac, char **av, char **env)
{
    args_t *flag = malloc(sizeof(args_t));

    if (usage_func(ac, av) == 1)
        return (0);
    if (error_handling(ac, av) == 84) {
        help(av);
        return (84);
    }
    if (parse_args(ac, av, flag) == 84) {
        help(av);
        return (84);
    }
    if ((env[0] == NULL) || (term(env, flag)) == 84) {
        if (print_debug(flag) == 84)
            return (84);
        my_putstr("Press any key to start Tetris");
        return (0);
    }
    if (my_popup(av, flag) == 84)
        return (84);
    return (0);
}