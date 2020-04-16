/*
** EPITECH PROJECT, 2019
** navy
** File description:
** next_round
*/

#include "my.h"

extern int global;

int input_gestion(char *coord_attack)
{
    if (my_strlen(coord_attack) != 3) {
        my_putstr("wrong position");
        return (84);
    }
    if ((coord_attack[0] < 'A' || coord_attack[0] > 'H') ||
        (coord_attack[1] < '1' || coord_attack[1] > '9')) {
        my_putstr("wrong position");
        return (84);
        }
    else
        return (0);
}

int coord_attack_player(output_t *output)
{
    int input = 0;
    char *coord_attack = NULL;

    coord_attack = malloc(sizeof(char) * 10);
    my_putstr("\nattack: ");
    if (read(0, coord_attack, 4) == 0)
        return (84);
    input = input_gestion(coord_attack);
    if (input == 84)
        coord_attack_player(output);
    else
        status_attack(output, coord_attack);
    sig(global, 1);
    my_putstr("\nwaiting for enemy's attack...\n");
    pause();
    return (0);
}

int coord_attack_player2_wrong(output_t *output)
{
    int input = 0;
    char *coord_attack = NULL;

    coord_attack = malloc(sizeof(char) * 10);
    my_putstr("\nattack: ");
    if (read(0, coord_attack, 4) == 0)
        return (84);
    input = input_gestion(coord_attack);
    if (input == 84)
        coord_attack_player2_wrong(output);
    else
        status_attack(output, coord_attack);
    sig(global, 1);
}

int coord_attack_player2(output_t *output)
{
    int eof = 0;

    my_putstr("\nwaiting for enemy's attack...\n");
    pause();
    eof = coord_attack_player2_wrong(output);
    if (eof == 84)
        return (84);
    return (0);
}

int next_round(output_t *output, int ac)
{
    int eof = 0;

    my_putstr("\nmy positions:\n");
    for (int i = 0; i < 10; i++)
        my_putstr(output->map[i]);
    my_putstr("\nenemy's positions:\n");
    for (int k = 0; k < 10; k++)
        my_putstr(output->map_e[k]);
    if (ac == 2) {
        if (coord_attack_player(output) == 84)
            output->eof = 84;
    }
    else if (ac == 3) {
        if (coord_attack_player2(output) == 84)
            output->eof = 84;
    }
    if (win(output) == 1) {
        my_putstr("\nI won !\n");
        return (1);
    }
    return (0);
}