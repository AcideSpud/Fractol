CC = gcc
CFLAGS = -Wall -Wextra -Werror 

NAME = fractol

SRC_NAME = main.c\
		   init.c\
		   event.c\
		   img.c\
		   error.c\
		   draw.c\
		   color.c\
		   cantor.c\
		   circle.c\
		   mandelbrot.c\
		   julia.c\
		   tools.c\
		   destroy.c\
		   init_julia.c\
		   init_douady.c\
		   init_mandelbrot.c\
		   douady.c

SRC_PATH = ./src/
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

SRCO_NAME = $(SRC_NAME:.c=.o)
SRCO_PATH = ./obj/
SRCO = $(addprefix $(SRCO_PATH), $(SRCO_NAME))

INCL_NAME =	fractol.h
INCL_PATH = ./includes/
INCL = $(addprefix $(INCL_PATH), $(INCL_NAME))

LIBFT_NAME = libft.a
LIBFT_PATH = ./libft/
LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))
LIBFT_INCL_PATH = ./libft/includes/
LIBFT_CC = -lft
LIBMLX_NAME = libmlx.a
LIBMLX_PATH = ./libmlx/
LIBMLX = $(addprefix $(LIBMLX_PATH), $(LIBMLX_NAME))
LIBMLX_CC = -lmlx
MLX_FRAMEWORK = -framework OpenGL -framework AppKit
LIB = -L $(LIBFT_PATH) $(LIBFT_CC) -L $(LIBMLX_PATH) $(LIBMLX_CC) -lm

all: $(LIBFT) $(LIBMLX) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(LIBMLX):
	make -C $(LIBMLX_PATH)

$(NAME): $(SRCO)
	$(CC) $(CFLAGS) $(MLX_FRAMEWORK) $(LIB) -o $(NAME) $(SRCO)
	@echo "\033[0;36m"$(NAME)" created\033[m"

clean:
	@make -C $(LIBFT_PATH) $@
	make -C $(LIBMLX_PATH) $@
	rm -rf $(SRCO_PATH)
	@echo "\033[0;32m"$(NAME)" objects cleaned\033[m"

clean_fclean:
	rm -rf $(SRCO_PATH)
	@echo "\033[0;32m"$(NAME)" objects cleaned\033[m"

fclean: clean_fclean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) $@
	make -C $(LIBMLX_PATH) $@
	@echo "\033[0;31m"$(NAME)" cleaned\033[m"

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INCL)
	@make -C $(LIBFT_PATH) $@

$(SRCO_PATH)%.o: $(SRC_PATH)%.c $(INCL)
	@if [ ! -d $(SRCO_PATH) ]; then \
        mkdir $(SRCO_PATH);\
        fi
	$(CC) $(CFLAGS) -I $(INCL_PATH) -I $(LIBFT_INCL_PATH) -I $(LIBMLX_PATH) -o $@ -c $<

.PHONY: all clean fclean re $(LIBFT) norme
