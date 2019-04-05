##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	cc

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/

SRC	=	$(D_SRC)main.c					\
		$(D_SRC)check.c					\
		$(D_SRC)init.c					\
		$(D_SRC)init_game.c				\
		$(D_SRC)update.c				\
		$(D_SRC)window.c				\
		$(D_SRC)time.c					\
		$(D_SRC)charge_room.c				\
		$(D_SRC)set_obj_in_room.c			\
		$(D_SRC)copy_room.c				\
		$(D_SRC)display_room.c				\
		$(D_SRC)movement.c				\
		$(D_SRC)moteur_3d/draw.c			\
		$(D_SRC)moteur_3d/line.c			\
		$(D_SRC)moteur_3d/iso.c				\
		$(D_SRC)moteur_3d/triangle.c			\
		$(D_SRC)moteur_3d/z_buff.c			\
		$(D_SRC)moteur_3d/display.c			\
		$(D_SRC)moteur_3d/transform.c			\
		$(D_SRC)moteur_3d/file_obj.c			\
		$(D_SRC)moteur_3d/init_obj.c			\
		$(D_SRC)moteur_3d/set_obj.c			\
		$(D_SRC)moteur_3d/my_getfloat.c			\
		$(D_SRC)moteur_3d/init_img.c			\
		$(D_SRC)moteur_3d/draw_poly.c			\
		$(D_SRC)moteur_3d/draw_poly_interpolation.c	\
		$(D_SRC)moteur_3d/draw_poly_init.c		\
		$(D_SRC)moteur_3d/set_triangle.c		\
		$(D_SRC)moteur_3d/charge_obj.c			\
		$(D_SRC)moteur_3d/movement_camera.c		\
		$(D_SRC)moteur_3d/rotation_camera.c		\
		$(D_SRC)moteur_3d/transform_camera.c		\

OBJ	=	$(SRC:%.c=$(BUILD_DIR)/%.o)

NAME	=	my_rpg

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy -l csfml-graphics -l csfml-system  -l csfml-window -lm -g
LDFLAGS_WAGNER += -L $(D_LIB) -lmy -lm -lc_graph_prog
BUILD_DIR = build

all:	$(NAME)

options:
	@echo "  CC       $(CC)"
	@echo "  CFLAGS   $(CFLAGS)"
	@echo "  LDFLAGS  $(LDFLAGS)"

$(BUILD_DIR)/%.o: %.c $(INC)
	@mkdir -p $(@D)
	@echo "  CC       $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "  RM       $(BUILD_DIR)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@$(MAKE) -C $(D_LIB) fclean --no-print-directory
	@echo "  RM       $(NAME)"
	@rm -f $(NAME) *~

libmy:
	@make -C $(D_LIB) --no-print-directory

$(NAME): libmy options $(OBJ)
	@echo "  BUILD    $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

wagner: libmy options $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS_WAGNER)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all options clean fclean re
