NAME = so_long

SRCS = so_long.c helpers/maps.c helpers/game.c helpers/player.c helpers/images.c helpers/window.c helpers/flood_fill.c \
utils/maps.c

LIBFT_DIR = ./lib/libft
LIBFT_NAME = libft.a 

MLX_DIR = ./lib/mlx
MLX_NAME = libmlx.a

CC = cc
CFLAGS = -Werror -Wall -Wextra -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): libft mlx
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_DIR)/$(LIBFT_NAME) $(MLX_DIR)/$(MLX_NAME) -o $(NAME)

libft: 
	make -C $(LIBFT_DIR)

mlx:
	make -C $(MLX_DIR)
	
clean: 
	make -C $(LIBFT_DIR) clean 
	make -C $(MLX_DIR) clean

fclean: clean 
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean 
	
re: fclean all