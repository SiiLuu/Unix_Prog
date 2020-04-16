/*
** EPITECH PROJECT, 2018
** getnbr
** File description:
** convert a char to int
*/

#include "../../include/my.h"

int to_bin(int dno)
{
    int bno = 0;
    int i = 0;
    int f = 1;

    while (dno != 0) {
        i = dno % 2;
        bno = bno + i * f;
        f = f * 10;
        dno = dno / 2;
    }
    return (bno);
}