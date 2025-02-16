SRC = *.c $(wildcard map/*.c) gnl/get_next_line.c gnl/get_next_line_utils.c 
NAME = so_long
FLAGS = -Wall -Werror -Wextra
MLX = -lmlx -L/usr/include/minilibx-linux/ -lXext -lX11
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(SRC)
	@cc  $^ $(MLX) -o $@
clean:
	@rm -rf $(NAME)
re: clean all 
test:
	cc test.c $(MLX) -o test
.PHONY: clean all re
