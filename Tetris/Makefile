##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the tetris
##

SRC 	=	src/main.c\
			src/error_handling.c\
			src/print_tetris.c\
			src/stat_tab.c\
			src/game_tab.c\
			src/game_loop.c\
			src/debug_mode.c\
			src/parse_args.c\
			src/str_to_word_tab.c\
			src/tetriminos.c\
			src/help_func.c\
			src/get_tetris_info.c\
			src/sort_tetri.c\
			src/errors_str.c\
			src/use_func.c

OBJ 	=	$(SRC:.c=.o)

NAME 	=	tetris

CFLAGS += -W -Wall -g3 -Wextra -pedantic -I./include

##LFLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		##make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS) -lcurses
clean:
	rm -f lib/my/*.o
	rm -f src/*.o
	rm -f lib/my/libmy.a
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all