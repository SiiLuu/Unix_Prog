##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile for compile my ls
##

SRC		=		src/my_ls.c\
				src/intermediate_ls.c\
				src/l_ls.c\
				src/use_func.c\
				src/tools.c

OBJ		=		$(SRC:.c=.o)

NAME	=		my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:	
		rm -f src/*.o

fclean:	clean
		rm -f $(NAME)

re:		fclean all