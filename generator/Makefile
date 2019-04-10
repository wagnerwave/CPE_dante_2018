##
## EPITECH PROJECT, 2018
## epitech makefile
## File description:
## makefile for rush2
##

D_SRC	=	./src/
D_INC	=	./include/

NAME	=	generator

SRC	=	$(D_SRC)algo_maze.c \
		$(D_SRC)resolve_map.c \
		$(D_SRC)maze.c \
		$(D_SRC)init.c \
		$(D_SRC)my_pow.c \
		$(D_SRC)init_map.c \
		$(D_SRC)main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -I$(D_INC) -lm -g

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	clean all

.PHONY	:	all clean fclean re
