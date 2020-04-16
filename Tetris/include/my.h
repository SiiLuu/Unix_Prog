/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#ifndef _MY_SOKOBAN_H_
#   define _MY_SOKOBAN_H_

    typedef struct args_s {
        char *f_L;
        char *f_l;
        char *f_r;
        char *f_t;
        char *f_d;
        char *f_q;
        char *f_p;
        char *f_map;
        char *f_w;
        char *n1;
        char *n2;
        int nb1;
        int nb2;
        int **collisions;
    }args_t;

    typedef struct tetrimino {
    char *tetris;
    int color;
    struct tetrimino *next;
    struct tetrimino *root;
    }tetrimino_t;

    int my_strlen(char const *str);
    void my_putnbr(int nb);
    int my_strcmp(char *s1, char *s2);
    int open_file(char *path);
    int usage_func(int ac, char **av);
    void my_putstr(char *s);
    void my_putchar(char c);
    void print_tetris(void);
    void print_stats(args_t *flag);
    void print_game_tab(args_t *flag);
    int my_popup(char **av, args_t *flag);
    int print_debug(args_t *flag);
    int parse_args(int ac, char **av, args_t *flag);
    void init_args(args_t *flag);
    int my_strcmp_limited(char *s1, char *s2);
    char *get_first_numbers(args_t *flag);
    char *get_second_numbers(args_t *flag);
    int my_getnbr(char *nb);
    int	count_files(void);
    int	name_tetri(int i);
    int info_tetri(char *tab);
    char *str_copy(char *s1, char *s2);
    char *str_cat(char *dest, char const *src);
    int	check_extrem(char *d_name);
    char **str_to_word_tab(char *str, char limit);
    char **show_tab(char **tab);
    char **sort_words(char **words, int count);
    char *errors_level(char **av, int i);
    char *get_name(char *d_name, char c);
    char *errors_l_flag(char **av, int i);
    int errors_no_args(char **av, int i);
    char *catch_key_size(char **av, int i);
    char **set_alphanum_order(char **tab, int count);
    int error_handling(int ac, char **av);
    tetrimino_t *init_tetrimino(tetrimino_t *tetrimino);
    tetrimino_t *get_tetris_info(tetrimino_t *tetrimino);
    void help(char **av);
    void name(char *tab);
    void print_keys(args_t *flag);
    int	count_files_nodraw(void);

#endif