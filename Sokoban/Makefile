##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile for compile my_sokoban
##

SRC		=		src/my_sokoban.c\
				src/use_func.c\
				src/tools.c\
				src/move.c\
				src/win_lose.c

OBJ		=		$(SRC:.c=.o)

NAME	=		my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses

clean:	
		rm -f src/*.o

fclean:	clean
		rm -f $(NAME)

re:		fclean all