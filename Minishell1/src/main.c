/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#include <signal.h>
#include <stdlib.h>
#include "minishell1.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    signal(SIGINT, SIG_IGN);
    my_putstr("my_prompt ~ >");
    body_code(env);
    return (0);
}