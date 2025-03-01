/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:04 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/01 18:09:03 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	lenght_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	flood_fill(t_node *map, int row_player, int colom_player)
{
	t_node	*row;
	int		size_row;
	int		size_colom;

	row = NULL;
	size_row = 0;
	size_colom = 0;
	row = ft_list_at(map, row_player);
	size_colom = lenght_line(map->line);
	size_row = list_size(map);
	if (row_player < 0 || colom_player < 0 || row_player >= size_row
		|| colom_player >= size_colom)
		return ;
	if (row->line[colom_player] == 'F' || row->line[colom_player] == '1'
		|| row->line[colom_player] == 'M')
		return ;
	row->line[colom_player] = 'F';
	flood_fill(map, row_player - 1, colom_player);
	flood_fill(map, row_player + 1, colom_player);
	flood_fill(map, row_player, colom_player - 1);
	flood_fill(map, row_player, colom_player + 1);
}
