/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** include for navy
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <stdarg.h>
#include <string.h>

typedef struct output {
    int return_status;
    int status_open;
    int eof;
    char **map;
    char **map_e;
}output_t;

void my_putchar(char c);
void my_putstr(char *str);
void vertical_boat_1(output_t *output, int k, int i, char **cord);
void vertical_boat_2(output_t *output, int k, int i, char **cord);
void vertical_boat_3(output_t *output, int k, int i, char **cord);
void vertical_boat_4(output_t *output, int k, int i, char **cord);
char **my_str_to_word_array(char *str);
int my_putnbr(int nb);
int player_2(int fd, output_t *output, char **av, char *position);
int player_1(int fd, output_t *output, char **av, char *position);
int boat_position(output_t *output);
int status_attack(output_t *output, char *coord_attack);
int my_strlen(char const *str);
int coord_attack_player(output_t *output);
int check_file(char *position, output_t *output);
char *int_to_char(int num);
int my_getnbr(char *str);
int create_map(output_t *output, char *position);
int my_putnbr_base_modified(int nbr, char const *base);
int my_putstr_modified(char const *str);
int my_putnbr_base(int nbr, char const *base);
int my_printf(char *str, ...);
int check_file_coord(char *position, output_t *output);
void help_func(void);
void init_map(output_t *output);
char *middle_map(int k, output_t *output);
char *mid(int k, output_t *output);
void init_enemy_map(output_t *output);
int init_game_p1(char *position, output_t *output);
int coord_attack(output_t *output);
int next_round(output_t *output, int ac);
void pid_users(void);
int chose_player(int ac, char **av, output_t *output);
unsigned int my_getnbr_base(char *str, char *base);
int my_strncmp(char *s1, char *s2, int n);
int my_strcmp(char const *s1, char const *s2);
void sig(int pid, int nb);
void catch_sig(void);
int win(output_t *output);
int coord_attack_player2(output_t *output);
int to_bin(int dno);
int binary_decimal(int n);
void check_letters(char **cord, int k, output_t *output);
void check_letters_2(char **cord, int k, output_t *output);

#endif