/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:44:38 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/02 14:26:56 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>

typedef struct node
{
	char		*line;
	struct node	*next;
}				t_node;

typedef struct s_data
{
	int			e;
	int			p;
	int			c;
	int			one;
	int			zero;
	int			m;
	void		*mlx;
	void		*win;
	void		*top;
	void		*bottom;
	void		*left;
	void		*right;
	void		*success;
	void		*collectible;
	void		*wall;
	void		*space;
	void		*door;
	void		*door_open;
	void		*enimy;
	void		*back_ground_moves;
	int			width_map;
	int			height_map;
	int			row_player;
	int			colom_player;
	int			colom_exit;
	int			row_exit;
	int			moves;
	int			succ;
	char		*str;
	t_node		*head;
}				t_data;

char			*ft_itoa(int n);
void			ft_putstr(int fd, char *s);
int				ft_putnbr(int n);
void			free_imgs(t_data *game);
int				key_hook(int key_code, t_data *vars);
t_node			*creat_node(char *line);
void			push_back(t_node **head, t_node *node);
void			free_list(t_node **head);
t_node			*ft_last_node(t_node *list);
int				check_wall(t_node *head);
int				check_caracter(t_data *data);
int				check_len(t_node *map);
void			check_map(t_data *data, t_node *map);
int				list_size(t_node *map);
t_node			*ft_list_at(t_node *begin, int pos);
void			flood_fill(t_node *map, int row_player, int colom_player);
void			return_coordinates(t_node *map, t_data *cooredinates);
int				lenght_line(char *str);
t_node			*map_copy(t_node *map);
int				check_caracter_after_flood_fill(t_node *map_copy);
void			put_img(t_node *map, t_data *img);
int				handle_close(t_data *game);
void			handle_exit(t_data *game);
#endif