/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:00 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/01 14:31:58 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	top_bottom(t_node *map)
{
	int		i;
	t_node	*last_node;

	i = 0;
	if (!map)
		return (0);
	last_node = ft_last_node(map);
	while (map->line[i] && last_node->line[i])
	{
		if (map->line[i] != '1' || last_node->line[i] != '1')
			return (ft_putstr(2,
					"Error\nyou have problem in wall (top or bottom) the map."),
				0);
		i++;
	}
	return (1);
}

int	sides(t_node *map)
{
	size_t	len;

	while (map)
	{
		len = ft_strlen(map->line);
		if (map->line[0] != '1' || map->line[len - 1] != '1')
		{
			return (ft_putstr(2,
					"Error\nyou have problem in wall (sides) the map."), 0.);
		}
		map = map->next;
	}
	return (1);
}

int	check_wall(t_node *head)
{
	if (top_bottom(head) == 0 || sides(head) == 0)
		return (0);
	return (1);
}
