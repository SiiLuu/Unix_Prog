/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** navy project
*/

#include "my.h"

extern int global;

void rec(int signb, siginfo_t *info, void *ptr)
{
    (void)ptr;
    if (signb == SIGUSR1 || signb == SIGUSR2)
        global = info->si_pid;
    usleep(1000);
}

void catch_sig(void)
{
    struct sigaction act;

    act.sa_sigaction = rec;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
}

void sig(int pid, int nb)
{
    if (nb == 0)
        kill(pid, SIGUSR1);
    if (nb == 1)
        kill(pid, SIGUSR2);
}

int win(output_t *output)
{
    int i = 0;
    int j = 0;
    int nb = 0;

    while (output->map[i]) {
        j = 0;
        while (output->map[i][j]) {
            if (output->map[i][j] == 'x')
                nb++;
            j++;
        }
        i++;
    }
    if (nb == 14)
        return (1);
    return (0);
}