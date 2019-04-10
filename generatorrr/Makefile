##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

D_SRC	=	./src/
D_INC	=	./include/

SRC	=	$(D_SRC)main.c		\
		$(D_SRC)init_map.c	\
		$(D_SRC)generate.c	\

OBJ	=	$(SRC:%.c=%.o)

NAME	=	generator

CFLAGS	=	-W -Wall -Wextra -I$(D_INC) -g

LDFLAGS	=	-lm

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@$(MAKE) clean
	@rm -f $(NAME)
	@rm -f *~

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
