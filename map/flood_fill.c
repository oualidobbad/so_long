#include "../so_long.h"
int		lenght_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return 0;
	while (str[i])
	{
		i++;
	}
	return i;
}

void flood_fill(s_node *map, int row, int colom)
{
	if (row < 0 || colom < 0 || row >= list_size(map) || colom >= lenght_line(map->line))
		return ;
	if ((ft_list_at(map, row))->line[colom] == 'F' || (ft_list_at(map, row))->line[colom] == '1')
		return ;
	(ft_list_at(map, row))->line[colom] = 'F';
	flood_fill(map, row - 1, colom);
	flood_fill(map, row + 1, colom);
	flood_fill(map, row, colom - 1);
	flood_fill(map, row, colom + 1);
}
