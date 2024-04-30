NAME = so_long


SRCS = main.c helpers/maps.c

LIBFT_DIR = ./lib/libft
LIBFT_NAME = libft.a 

CC = cc
CFLAGS = -Werror 

all: $(NAME)

$(NAME): libft 
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME)

libft: 
	make -C $(LIBFT_DIR)
	
clean: 
	make -C $(LIBFT_DIR) clean 

fclean: clean 
	rm -rf $(NAME)
	
re: fclean all