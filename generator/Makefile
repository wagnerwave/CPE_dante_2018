##
## EPITECH PROJECT, 2018
## epitech makefile
## File description:
## makefile for rush2
##

D_SRC	=	./src/
D_INC	=	./include/

NAME	=	generator

SRC	=	$(D_SRC)algo_imperfect.c \
		$(D_SRC)imperfect.c \
		$(D_SRC)perfect.c \
		$(D_SRC)init.c \
		$(D_SRC)main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -I$(D_INC) -g

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	clean all

.PHONY	:	all clean fclean re
