/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** minishell 1
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

char *get_next_line(const int);
char **str_to_word_tab_limited(char *, char);
int	count_words(char *, char);
int	word_len(char *, char);
void body_code(char **);
char *get_home(char **);
int	my_strcmp(char *, char *);
int	my_free_tab(char **);
char **get_command(char **, char **, char **);
char *my_strcat(char *, char *);
char *get_path(char **);
void my_putstr(char *);
void my_putchar(char);
void my_puterr(char *);
int	my_strlen(char *);
char *my_strcpy(char *, char *);
char **do_command(char **, char **, char **);
int	count_tab(char **);
int	exec_it(char **, char *, char **);
int	my_exec(char **, char **);
char **show_env(char **, char **);
char **parse_replace_in_env(char *, char **);
char *write_all(char *, char *);
char *write_prec(char *);
char *write_next(char *, char *);
char *my_strdup(char *);
int	my_fork(char **, char *, char **);
char **my_fork2(char **, char **);
char **write_in_env(char **, char **);
int	detect_pos(char *, char **);
char **replace_in_env(char **, char **);
char **do_setenv(char **, char **);
char **do_unset(char **, char **);
char *exec_name(char *);
char *cpy_pwd(char *, char *, char *);
int	last_name(char *);

#endif