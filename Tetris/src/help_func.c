/*
** EPITECH PROJECT, 2018
** use_func
** File description:
** tools.
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    else
        my_putchar(nb + '0');
}

void help(char **av)
{
    my_putstr("USAGE  ");
    my_putstr(av[0]);
    my_putstr(" [options]\n");
    my_putstr("Options:\n --help               Display this help\n -L --");
    my_putstr("level={num}     Start Tetris at level num (def; 1)\n -l -");
    my_putstr("-key-left={K}    Move the tetrimino LEFT using the K key");
    my_putstr(" (def: left arrow)\n -r --key-right={K}   Move the tetrim");
    my_putstr("ino RIGHT using the K key (def: right arrow)\n -t --key-t");
    my_putstr("urn={K}    TURN the tetrimino clockwise 90d using the K k");
    my_putstr("ey (def: top arrow)\n -d --key-drop={K}    DROP the tetri");
    my_putstr("mino using the K key (def: down arrow)\n -q --key-quit={K");
    my_putstr("     QUIT the game using the K key (def: 'q' key)\n -p --");
    my_putstr("key-pause={K}   PAUSE/RESTART the game using the K key (d");
    my_putstr("ef: space bar)\n --map-size={row,col} Set the numbers of ");
    my_putstr("rows and columns of the map (def: 20,10)\n -w");
    my_putstr(" --without-next    Hide next tetrimino (def");
    my_putstr(": false)\n -D --debug           Debug mode (def: flase)\n");
}

int usage_func(int ac, char **av)
{
    if (((ac == 2) && av[1][0] == '-' && av[1][1] == 'h') ||
        ((ac == 2) &&  !my_strcmp(av[1], "--help"))) {
        help(av);
        return (1);
    }
    return (0);
}