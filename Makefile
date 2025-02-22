SRCS = imgs_hooks/ft_putnbr.c imgs_hooks/hooks.c imgs_hooks/push_img.c main/so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c map_check/check_caracter.c map_check/check_map.c map_check/check_wall.c map_check/flood_fill.c map_check/linked_list.c map_check/map_copy.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -L/usr/include/minilibx-linux -lmlx -lXext -lX11
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
