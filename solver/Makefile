##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/

SRC	=	$(D_SRC)main.c		\
		$(D_SRC)get_map.c	\
		$(D_SRC)free_map.c	\
		$(D_SRC)init_map.c	\
		$(D_SRC)resolve_map.c	\

OBJ	=	$(SRC:%.c=%.o)

NAME	=	solver

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy -lm

all: $(NAME)

libmy:
	@make -C $(D_LIB)

clean:
	@rm -f $(OBJ)

fclean:
	@$(MAKE) clean
	@$(MAKE) -C $(D_LIB) fclean
	@rm -f $(NAME)
	@rm -f *~

$(NAME): $(OBJ)
	@$(MAKE) -C lib/my
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
