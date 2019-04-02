##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## CPE_dante_2018 Makefile
##

SOLVER_DIR	=	./solver/
GENERATOR_DIR	=	./generator/

all	:
		@make -C $(SOLVER_DIR)
		@make -C $(GENERATOR_DIR)

clean	:
		@make clean -C $(SOLVER_DIR)
		@make clean -C $(GENERATOR_DIR)

fclean	:
		@make fclean -C $(SOLVER_DIR)
		@make fclean -C $(GENERATOR_DIR)

re	:	fclean all
