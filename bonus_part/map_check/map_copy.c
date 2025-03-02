/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:12 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/02 14:29:18 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_node	*map_copy(t_node *map)
{
	t_node	*map_copy;
	t_node	*node;

	map_copy = NULL;
	while (map)
	{
		node = creat_node(map->line);
		if (!node)
			return (free_list(&map), free_list(&map_copy), NULL);
		push_back(&map_copy, node);
		map = map->next;
	}
	return (map_copy);
}
