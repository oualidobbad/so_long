#ifndef SO_LONG
# define SO_LONG

# include "/usr/include/minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>

typedef struct node
{
	char		*line;
	struct node	*next;
}				s_node;

typedef struct s_data
{
	int			e;
	int			p;
	int			c;
	int			one;
	int			zero;
	void		*mlx;
	void		*win;
	void		*caracter;
	void		*collectible;
	void		*wall;
	void		*space;
	void		*door;
	int			width_map;
	int			height_map;
	int			row_player;
	int			colom_player;
	int			colom_exit;
	int			row_exit;
	int			moves;
	s_node		*head;
}				t_data;

void			handl_close(t_data *vars);
int				key_hook(int key_code, t_data *vars);
s_node			*creat_node(char *line);
void			push_back(s_node **head, s_node *node);
void			free_list(s_node **head);
s_node			*ft_last_node(s_node *list);
int				check_wall(s_node *head);
int				check_caracter(t_data *);
int				check_len(s_node *map);
void			check_map(t_data *data, s_node *map);
int				list_size(s_node *map);
s_node			*ft_list_at(s_node *begin, int pos);
void			flood_fill(s_node *map, int row_player, int colom_player);
void			return_coordinates(s_node *map, int *row_player, int *colom_player);
int				lenght_line(char *str);
s_node			*map_copy(s_node *map);
int				check_caracter_after_flood_fill(s_node *map_copy);
void			put_img(void *mlx, void *win_mlx, s_node *map, t_data *img);
void	handle_close(t_data *game);
#endif