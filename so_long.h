#ifndef SO_LONG
# define SO_LONG

# include "GNL/get_next_line.h"
# include <stdio.h>

typedef struct node
{
	char		*line;
	struct node	*next;
}				s_node;

typedef struct caracters
{
	int			e;
	int			p;
	int			c;
	int			one;
	int			zero;
}				s_caracters;

s_node			*creat_node(char *line);
void			push_back(s_node **head, s_node *node);
void			free_list(s_node **head);
s_node			*ft_last_node(s_node *list);
int				check_wall(s_node *head);
int				check_caracter(s_node *map);
int				check_len(s_node *map);
void			check_map(s_node *map);
int				list_size(s_node *map);
s_node			*ft_list_at(s_node *begin, int pos);
void			flood_fill(s_node *map, int row, int colom);
void			return_coordinates(s_node *map, int *row, int *colom);
int				lenght_line(char *str);
s_node			*map_copy(s_node *map);
int				check_caracter_after_flood_fill(s_node *map_copy);
#endif