#include "so_long.h"

void  return_coordinates(s_node *map, int *row_player, int *colom_player)
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
				*colom_player = i;
				*row_player = j;
				return ;
			}
			i++;
		}
		j++;
		map = map->next;
	}
}
