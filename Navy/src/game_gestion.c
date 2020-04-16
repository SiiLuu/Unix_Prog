/*
** EPITECH PROJECT, 2019
** navy
** File description:
** game gestion
*/

#include "my.h"

extern int global;

int init_game_p1(char *position, output_t *output)
{
    create_map(output, position);
    boat_position(output);
    if (output->return_status == 84)
        return (84);
    pid_users();
    my_putstr("\nwaiting for enemy connection...\n\n");
    catch_sig();
    pause();
    sig(global, 1);
    my_putstr("enemy connected\n\n");
    if (output->return_status == 84)
        return (84);
    my_putstr("my positions:\n");
    for (int k = 0; k < 10; k++)
        my_putstr(output->map[k]);
    my_putstr("\nenemy's positions:\n");
    init_enemy_map(output);
    for (int i = 0; i < 10; i++)
        my_putstr(output->map_e[i]);
    coord_attack_player(output);
    return (0);
}

int init_game_p2(char **av, char *position, output_t *output)
{
    create_map(output, position);
    boat_position(output);
    if (output->return_status == 84)
        return (84);
    pid_users();
    my_putchar('\n');
    sig(my_getnbr(av[1]), 0);
    catch_sig();
    pause();
    my_putstr("successfully connected\n\n");
    if (output->return_status == 84)
        return (84);
    my_putstr("my positions:\n");
    for (int k = 0; k < 10; k++)
        my_putstr(output->map[k]);
    my_putstr("\nenemy's positions:\n");
    init_enemy_map(output);
    for (int i = 0; i < 10; i++)
        my_putstr(output->map_e[i]);
    coord_attack_player2(output);
    return (0);
}

int player_1(int fd, output_t *output, char **av, char *position)
{
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (84);
    read(fd, position, 32);
    close(fd);
    check_file(position, output);
    if (output->return_status == 84)
        return (84);
    if (init_game_p1(position, output) == 84)
        return (84);
    return (0);
}

int player_2(int fd, output_t *output, char **av, char *position)
{
    fd = open(av[2], O_RDONLY);
    if (fd == -1)
        return (84);
    read(fd, position, 32);
    close(fd);
    check_file(position, output);
    if (output->return_status == 84)
        return (84);
    if (init_game_p2(av, position, output) == 84)
        return (84);
}
