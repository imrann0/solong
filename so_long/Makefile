NAME = so_long

LIBFT = Libfth
LIBFTM = Libfth/libft.a
CFLAGS = -g -Wall -Wextra -Werror
MLX = -Lminilibx -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c \
		so_long_utils.c \
		ft_get_next_line.c \
		charcter.c \
		charcter_utils.c \
		ft_check.c \
		ft_error.c \
		ft_path_finder.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C minilibx/
	cc $(CFLAGS) $(OBJ) $(LIBFTM) $(MLX) -o $(NAME)

clean:
	make -C $(LIBFT) clean
	make -C minilibx clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
