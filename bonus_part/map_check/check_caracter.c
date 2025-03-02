/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_caracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:44:49 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/02 14:28:47 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	init_caracter(t_data *data, int i, t_node *map)
{
	if (!map)
		return (0);
	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == '1')
				data->one++;
			else if (map->line[i] == '0' || map->line[i] == 'M')
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

int	check_caracter_after_flood_fill(t_node *map_copy)
{
	int	i;

	i = 0;
	if (!map_copy)
		return (0);
	while (map_copy)
	{
		i = 0;
		while (map_copy->line[i])
		{
			if (map_copy->line[i] == 'C' || map_copy->line[i] == 'E')
			{
				ft_putstr(2, "Error\nThe player will not reach");
				ft_putstr(2, " EXIT or Collectible check map.");
				return (0);
			}
			i++;
		}
		map_copy = map_copy->next;
	}
	return (1);
}

int	check_caracter(t_data *data)
{
	data->e = 0;
	data->one = 0;
	data->zero = 0;
	data->p = 0;
	data->c = 0;
	data->m = 0;
	if (init_caracter(data, 0, data->head) == 0)
		return (ft_putstr(2,
				"Error\nYou have additional char Check caracters of map."), 0);
	if (data->c >= 1 && data->e == 1 && data->p == 1)
		return (1);
	else
	{
		ft_putstr(2, "Error\nyou must have less than one ");
		ft_putstr(2, "COLLECTIBLE and one EXIT or one PLAYER check map.");
		return (0);
	}
}
