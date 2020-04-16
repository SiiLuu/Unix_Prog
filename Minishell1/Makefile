
## EPITECH PROJECT, 2018
## minishell 1
## File description:
## minishell 1
##

CFLAGS	+= -I./include

NAME	= mysh

SRCS	= src/main.c \
		  src/str_to_word_tab_limited.c \
		  src/tools.c \
		  src/use_func.c \
		  src/body_code.c \
		  src/get_path.c \
		  src/command.c \
		  src/parse_env.c \
		  src/rep_env.c \
		  src/fork.c \
		  src/env.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all