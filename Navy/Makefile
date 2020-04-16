##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the minishell1
##

SRC 	=	src/main.c\
			src/help_func.c\
			src/navy.c\
			src/init_enemy_map.c\
			src/init_game.c\
			src/vertical_boat.c\
			src/next_round.c\
			src/signal.c\
			src/files_error.c\
			src/game_gestion.c\
			src/attack_gestion.c

OBJ 	=	$(SRC:.c=.o)

NAME 	=	navy

CFLAGS += -W -Wall -Wextra -g3 -pedantic -I./include

LFLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)
clean:
	rm -f lib/my/*.o
	rm -f src/*.o
	rm -f lib/my/libmy.a
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all