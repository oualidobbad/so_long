SRCS = mandatory_part/main/ft_putnbr.c \
       mandatory_part/main/destroy_free.c \
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
       mandatory_part/map_check/map_copy.c \
       mandatory_part/main/ft_putstr.c

SRC_BONUS = bonus_part/main/ft_putnbr.c \
       bonus_part/main/destroy_free.c \
       bonus_part/imgs_hooks/hooks.c \
       bonus_part/imgs_hooks/push_img.c \
       bonus_part/main/so_long.c \
       bonus_part/gnl/get_next_line.c \
       bonus_part/gnl/get_next_line_utils.c \
       bonus_part/map_check/check_caracter.c \
       bonus_part/map_check/check_map.c \
       bonus_part/map_check/check_wall.c \
       bonus_part/map_check/flood_fill.c \
       bonus_part/map_check/linked_list.c \
       bonus_part/map_check/map_copy.c \
       bonus_part/main/ft_putstr.c \
	bonus_part/main/ft_itoa.c

OBJS = $(SRCS:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -lXext -lX11 -L/usr/include/minilibx-linux 
NAME = so_long
NAME_BONUS = so_long_bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all 
re_bonnus: fclean bonus

.SECONDARY: $(OBJ_BONUS) $(OBJS)
.PHONY: all clean fclean
