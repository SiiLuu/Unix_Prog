/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban.h
*/

#ifndef _MY_SOKOBAN_H_
# define _MY_SOKOBAN_H_

void my_putstr(char *s);
void move_up(char *str);
void move_down(char *str);
int error_box(char *str);
void move_right(char *str);
void move_left(char *str);
int error_player(char *str);
int calc_distance_x(char *str);
int calc_distance_y(char *str);
int my_strlen(char *str);
int error_char(int ac, char *str);
int open_file(char *path);
void usage_func(int ac, char **av);
int check_win(char *str);
void check_status(char *str);

#endif