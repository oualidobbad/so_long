#include "../so_long.h"

int	init_caracter(t_data *data, int i, s_node *map )
{
	if (!map)
		return 0;
	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == '1')
				data->one++;
			else if (map->line[i] == '0')
				data->zero++;
			else if (map->line[i] == 'E')
				data->e++;
			else if (map->line[i] == 'P')
				data->p++;
			else if (map->line[i] == 'C')
				data->c++;
			else
				return (0);
			i++;
		}
		map = map->next;
	}
    return (1);
}

int check_caracter_after_flood_fill(s_node *map_copy)
{
	int i;

	i = 0;
	if (!map_copy)
		return 0;
	while (map_copy)
	{
		i = 0;
		while (map_copy->line[i])
		{
			if (map_copy->line[i] == 'C' || map_copy->line[i] == 'E')
			{
				write (2, "map invalid\n", 12);
				return 0;
			}
			i++;	
		}
		map_copy = map_copy->next;
	}
	return 1;
}

int	check_caracter(t_data *data)
{

	data->one = data->zero = data->e = data->p = data->c = 0;
	if (init_caracter(data, 0, data->head) == 0)
        return (0);
	if (data->c >= 1 && data->e == 1 && data->p == 1
		&& data->zero >= 1)
		return (1);
	else
		return (0);
}
