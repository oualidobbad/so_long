SRCS = *.c $(wildcard map/*.c) gnl/get_next_line.c gnl/get_next_line_utils.c 
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
INCLUDES = -I/usr/include
MLX = -L/usr/lib -lmlx -lXext -lX11
OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


