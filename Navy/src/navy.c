/*
** EPITECH PROJECT, 2019
** PSU_navy
** File description:
** code a battleship betwen 2 player
*/

#include "my.h"

void check_cord(output_t *output, int k, int i, char **cord)
{
    if ((output->map[0][i] >= cord[1][2] && output->map[0][i] <= cord[1][5])
        && (k - 1 + '0' == cord[1][3])) {
        (cord[1][3] == cord[1][6]) ? (output->map[k][i] = cord[1][0]) :
        (vertical_boat_2(output, k, i, cord));
    }
    if ((output->map[0][i] >= cord[2][2] && output->map[0][i] <= cord[2][5])
        && (k - 1 + '0' == cord[2][3])) {
        (cord[2][3] == cord[2][6]) ? (output->map[k][i] = cord[2][0]) :
        (vertical_boat_3(output, k, i, cord));
    }
    if ((output->map[0][i] >= cord[3][2] && output->map[0][i] <= cord[3][5])
        && (k - 1 + '0' == cord[3][3])) {
        (cord[3][3] == cord[3][6]) ? (output->map[k][i] = cord[3][0]) :
        (vertical_boat_4(output, k, i, cord));
    }
}

void print_boat(output_t *output, char *position)
{
    char **cord = my_str_to_word_array(position);

    int k = 2;
    int i = 2;

    while (k < 10) {
        while (output->map[k][i] != '\n') {
            if ((output->map[0][i] >= cord[0][2] &&
            output->map[0][i] <= cord[0][5]) && (k - 1 + '0' == cord[0][3])) {
                (cord[0][3] == cord[0][6]) ? (output->map[k][i] = cord[0][0])
                : (vertical_boat_1(output, k, i, cord));
            }
            check_cord(output, k, i, cord);
            i++;
        }
        i = 2;
        k++;
    }
}

char *middle_map(int k, output_t *output)
{
    int i = 2;

    output->map[k] = malloc(sizeof(char) * 19);
    output->map[k][0] = k - 1 + '0';
    output->map[k][1] = '|';
    while (i < 17) {
        (i % 2 != 0) ? (output->map[k][i] = ' ') : (output->map[k][i] = '.');
        i++;
    }
    output->map[k][17] = '\n';
    output->map[k][18] = '\0';
    return (output->map[k]);
}

void init_map(output_t *output)
{
    int k = 0;

    while (k < 10) {
        if (k == 0)
            output->map[k] = " |A B C D E F G H\n";
        if (k == 1)
            output->map[k] = "-+---------------\n";
        if (k > 1)
            output->map[k] = middle_map(k, output);
        k++;
    }
}

int create_map(output_t *output, char *position)
{
    output->map = malloc(sizeof(char *) * 10);
    output->map_e = malloc(sizeof(char *) * 10);
    check_file_coord(position, output);
    if (output->return_status == 84)
        return (84);
    init_map(output);
    print_boat(output, position);
    free(position);
    return (0);
}