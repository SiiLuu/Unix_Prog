/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** navy project
*/

#include "my.h"

void pid_users(void)
{
    pid_t i = getpid();

    my_putstr("my_pid: ");
    my_putnbr(i);
}

int boat_position(output_t *output)
{
    int k = 2;
    int i = 2;
    int number = 0;

    while (k < 10) {
        while (i < 17) {
            if ((output->map[k][i] == '2') || (output->map[k][i] == '3') ||
                (output->map[k][i] == '4') || (output->map[k][i] == '5'))
                number++;
            i++;
        }
        i = 2;
        k++;
    }
    if (number != 14)
        output->return_status = 84;
    return (0);
}

int chose_player(int ac, char **av, output_t *output)
{
    char *position = NULL;
    int fd = 0;
    int error = 0;

    position = malloc(sizeof(char) * 32);
    if (ac == 2) {
        error = player_1(fd, output, av, position);
        if (error == 84)
            output->return_status = 84;
    }
    else if (ac == 3) {
        error = player_2(fd, output, av, position);
        if (error == 84)
            output->return_status = 84;
    }
    return (0);
}