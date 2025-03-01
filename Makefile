SRCS = mandatory_part/imgs_hooks/ft_putnbr.c \
       mandatory_part/imgs_hooks/hooks.c \
       mandatory_part/imgs_hooks/push_img.c \
       mandatory_part/main/so_long.c \
       mandatory_part/gnl/get_next_line.c \
       mandatory_part/gnl/get_next_line_utils.c \
       mandatory_part/map_check/check_caracter.c \
       mandatory_part/map_check/check_map.c \
       mandatory_part/map_check/check_wall.c \
       mandatory_part/map_check/flood_fill.c \
       mandatory_part/map_check/linked_list.c \
       mandatory_part/map_check/map_copy.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -L/usr/include/minilibx-linux -lmlx -lXext -lX11
OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
