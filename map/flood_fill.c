#include "../so_long.h"
int		lenght_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return 0;
	while (str[i])
		i++;
	return i;
}

void flood_fill(s_node *map, int row_player, int colom_player)
{
	if (row_player < 0 || colom_player < 0 || row_player >= list_size(map) || colom_player >= lenght_line(map->line))
		return ;
	if ((ft_list_at(map, row_player))->line[colom_player] == 'F' || (ft_list_at(map, row_player))->line[colom_player] == '1')
		return ;
	(ft_list_at(map, row_player))->line[colom_player] = 'F';
	flood_fill(map, row_player - 1, colom_player);
	flood_fill(map, row_player + 1, colom_player);
	flood_fill(map, row_player, colom_player - 1);
	flood_fill(map, row_player, colom_player + 1);
}
