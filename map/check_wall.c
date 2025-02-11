#include "../so_long.h"

int	top_bottom(s_node *map)
{
	int		i;
	s_node	*last_node;

	i = 0;
	if (!map)
		return (0);
	last_node = ft_last_node(map);
	while (map->line[i] && last_node->line[i])
	{
		if (map->line[i] != '1' || last_node->line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
int	sides(s_node *map)
{
	size_t	len;

	while (map)
	{
		len = ft_strlen(map->line);
		if (map->line[0] != '1' || map->line[len - 1] != '1')
		{
			return (0);
		}
		map = map->next;
	}
	return (1);
}

int	check_wall(s_node *head)
{
	if (top_bottom(head) == 0 || sides(head) == 0)
		return (0);
	return (1);
}
