/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** function to execute the and command
*/
#include "my.h"
#include <errno.h>

int check_return(int return_value)
{
    if (return_value > 0)
        return (1);
    else
        return (0);
    return (0);
}