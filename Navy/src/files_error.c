/*
** EPITECH PROJECT, 2019
** navy
** File description:
** file_error
*/

#include "my.h"

int check_file_4(char *position, output_t *output)
{
    char **cord = my_str_to_word_array(position);
    int k = 0;

    while (k != 4) {
        if (cord[k][2] == cord[k][5])
            check_letters(cord, k, output);
        if (cord[k][2] != cord[k][5])
            check_letters_2(cord, k, output);
        k++;
    }
    return (0);
}

int check_file_3(char *position, output_t *output)
{
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;

    if (position[0] == '2')
        two++;
    if (position[8] == '3')
        three++;
    if (position[16] == '4')
        four++;
    if (position[24] == '5')
        five++;
    if (two != 1 || three != 1 || four != 1 || five != 1)
        output->return_status = 84;
    check_file_4(position, output);
    return (0);
}

int check_file_2(char *position, output_t *output)
{
    if ((position[3] < '1' || position[3] > '9') ||
        (position[6] < '1' || position[6] > '9') ||
        (position[11] < '1' || position[11] > '9') ||
        (position[14] < '1' || position[14] > '9') ||
        (position[19] < '1' || position[19] > '9') ||
        (position[22] < '1' || position[22] > '9') ||
        (position[27] < '1' || position[27] > '9') ||
        (position[30] < '1' || position[30] > '9'))
        output->return_status = 84;
    if ((position[0] < '2' || position[0] > '5') ||
        (position[8] < '2' || position[8] > '5') ||
        (position[16] < '2' || position[16] > '5') ||
        (position[24] < '2' || position[24] > '5'))
        output->return_status = 84;
    check_file_3(position, output);
    return (0);
}

int check_file(char *position, output_t *output)
{
    int i = 0;
    int space = 0;

    while (position[i] != '\0') {
        if (position[i] == ':')
            space++;
        i++;
    }
    if ((position[2] < 65 || position[2] > 72) ||
        (position[5] < 65 || position[5] > 72) ||
        (position[10] < 65 || position[10] > 72) ||
        (position[13] < 65 || position[13] > 72) ||
        (position[18] < 65 || position[18] > 72) ||
        (position[21] < 65 || position[21] > 72) ||
        (position[26] < 65 || position[26] > 72) ||
        (position[29] < 65 || position[29] > 72))
        output->return_status = 84;
    if (i != 31 || space != 8)
        output->return_status = 84;
    check_file_2(position, output);
    return (0);
}

int check_file_coord(char *position, output_t *output)
{
    int i = 0;

    while (position[i] != '\0') {
        i++;
    }
    if (i != 31)
        output->return_status = 84;
    return (0);
}