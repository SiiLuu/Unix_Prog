/*
** EPITECH PROJECT, 2018
** tools
** File description:
** tools.
*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static struct option long_options[] = {
    {"level=",        required_argument, 0, 0},
    {"key-left=",     required_argument, 0, 0},
    {"key-right=",    required_argument, 0, 0},
    {"key-turn=",     required_argument, 0, 0},
    {"key-drop=",     required_argument, 0, 0},
    {"key-quit=",     required_argument, 0, 0},
    {"key-pause=",    required_argument, 0, 0},
    {"map-size=",     required_argument, 0, 0},
    {"without-next",  no_argument,       0, 0},
    {"debug",         no_argument,       0, 0},
    {0,                 0,               0, 0},
};

char *catch_key(char **av, int i)
{
    int j = 0;
    char *key = malloc(sizeof(char) + 5);

    for (; av[i][j] != '='; j++);
    if (av[i][j + 1] == '\0')
        return (NULL);
    j++;
    for (int k = 0; av[i][j] != '\0'; j++, k++)
        key[k] = av[i][j];
    return (key);
}

int parse_args4(char **av, args_t *flag, int i)
{
    if (!my_strcmp_limited(av[i], "--level="))
        if (((flag->f_L = errors_level(av, i)) == NULL))
            return (84);
    if (!my_strcmp_limited(av[i], "--key-left="))
        if ((flag->f_l = catch_key(av, i)) == NULL)
            return (84);
    if (!my_strcmp_limited(av[i], "--key-right="))
        if ((flag->f_r = catch_key(av, i)) == NULL)
            return (84);
    if (!my_strcmp_limited(av[i], "--key-turn="))
        if ((flag->f_t = catch_key(av, i)) == NULL)
            return (84);
    if (!my_strcmp_limited(av[i], "--key-drop="))
        if ((flag->f_d = catch_key(av, i)) == NULL)
            return (84);
    if (!my_strcmp_limited(av[i], "--key-quit="))
        if ((flag->f_q = catch_key(av, i)) == NULL)
            return (84);
    return (0);
}

int parse_args3(char **av, args_t *flag, int i)
{
    if (!my_strcmp(av[i], "-p"))
        if ((flag->f_p = av[i + 1]) == NULL)
            return (84);
    if (!my_strcmp(av[i], "-w") || !my_strcmp(av[i], "--without-next")) {
        if (errors_no_args(av, i) == 84)
            return (84);
        else
            flag->f_w = "No";
    }
    if (!my_strcmp(av[i], "--debug") || !my_strcmp(av[i], "-D"))
        if (errors_no_args(av, i) == 84)
            return (84);
    if (!my_strcmp_limited(av[i], "--key-pause="))
        if ((flag->f_p = catch_key(av, i)) == NULL)
            return (84);
    if (!my_strcmp_limited(av[i], "--map-size="))
        if ((flag->f_map = catch_key_size(av, i)) == NULL)
            return (84);
    return (0);
}

int parse_args2(char **av, args_t *flag, int i)
{
    if (!my_strcmp(av[i], "-L"))
        if ((flag->f_L = errors_l_flag(av, i)) == NULL)
            return (84);
    if (!my_strcmp(av[i], "-l"))
        if ((flag->f_l = av[i + 1]) == NULL)
            return (84);
    if (!my_strcmp(av[i], "-r"))
        if ((flag->f_r = av[i + 1]) == NULL)
            return (84);
    if (!my_strcmp(av[i], "-t"))
        if ((flag->f_t = av[i + 1]) == NULL)
            return (84);
    if (!my_strcmp(av[i], "-d"))
        if ((flag->f_d = av[i + 1]) == NULL)
            return (84);
    if (!my_strcmp(av[i], "-q"))
        if ((flag->f_q = av[i + 1])  == NULL)
            return (84);
    return (0);
}

int parse_args(int ac, char **av, args_t *flag)
{
    int a = 0;
    int option_index = 0;
    struct option;

    init_args(flag);
    for (int i = 0; av[i] != NULL; i++) {
        if (parse_args2(av, flag, i) == 84)
            return (84);
        if (parse_args3(av, flag, i) == 84)
            return (84);
        if (parse_args4(av, flag, i) == 84)
            return (84);
    }
    opterr = 0;
    while ((a = getopt_long(ac, av, "LlrtdqpwD", long_options,
        &option_index)) != -1)
        if (a == '?')
            return (84);
    return (0);
}