/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:44:55 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/22 17:16:47 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_len(t_node *map)
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

void	check_map(t_data *data, t_node *map)
{
	t_node	*copy;

	copy = map_copy(map);
	return_coordinates(copy, data);
	flood_fill(copy, data->row_player, data->colom_player);
	if (check_len(map) == 0 || check_caracter(data) == 0
		|| check_wall(map) == 0)
	{
		perror("Error\nmap invalid");
		free_list(&copy);
		free_list(&map);
		exit(0);
	}
	else if (check_caracter_after_flood_fill(copy) == 0)
	{
		free_list(&copy);
		free_list(&map);
		exit(0);
	}
	free_list(&copy);
}
