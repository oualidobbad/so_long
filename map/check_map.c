#include "../so_long.h"

int	check_len(s_node *map)
{
	size_t	len;

	if (!map)
		return (0);
	len = ft_strlen(map->line);
	while (map)
	{
		if (len != ft_strlen(map->line))
			return (0);
		map = map->next;
	}
	return (1);
}

void check_map(t_data *data, s_node *map)
{
	int row;
	int colom;
	s_node *copy;

	row = 0;
	colom = 0;
	copy= map_copy(map);
	return_coordinates(copy, &row, &colom);
	flood_fill(copy, row, colom);
	if (check_len(map) == 0 || check_caracter(data) == 0 || check_wall(map) == 0)
	{
		printf ("error\n");
		free_list(&copy);
		free_list (&map);
		exit (0);
	}
	else if (check_caracter_after_flood_fill(copy) == 0)
	{
		free_list(&copy);
		free_list (&map);
		exit (0);
	}
	free_list(&copy);
}
