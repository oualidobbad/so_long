#include "so_long.h"

void  return_coordinates(s_node *map, t_data *coordinates)
{
	int i;
	int j;
	
	j = 0;
	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == 'P')
			{
				coordinates->colom_player = i;
				coordinates->row_player = j;
				return ;
			}
			i++;
		}
		j++;
		map = map->next;
	}
}
