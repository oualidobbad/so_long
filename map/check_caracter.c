#include "../so_long.h"

int	init_caracter(s_node *map, s_caracters *caracter, int i)
{
	if (!caracter || !map)
		return 0;
	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == '1')
				caracter->one++;
			else if (map->line[i] == '0')
				caracter->zero++;
			else if (map->line[i] == 'E')
				caracter->e++;
			else if (map->line[i] == 'P')
				caracter->p++;
			else if (map->line[i] == 'C')
				caracter->c++;
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
	s_node *tmp;

	i = 0;
	tmp = map_copy;
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

int	check_caracter(s_node *map)
{
	s_caracters	caracter;

	caracter.one = caracter.zero = caracter.e = caracter.p = caracter.c = 0;
	if (init_caracter(map, &caracter, 0) == 0)
        return (0);
	if (caracter.c >= 1 && caracter.e == 1 && caracter.p == 1
		&& caracter.zero >= 1)
		return (1);
	else
		return (0);
}
