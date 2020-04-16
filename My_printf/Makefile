##
## MAkefile for:
## the my_printf function.
##

SRC=	my_printf.c \
		my_printf2.c \
		use_fonc.c \
		use_fonc2.c \

OBJ=	$(SRC:.c=.o)

NAME= 	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f libmy.a
	rm -f $(OBJ)

re:		fclean all