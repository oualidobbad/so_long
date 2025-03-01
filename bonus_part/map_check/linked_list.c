/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:08 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/22 15:47:27 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_node	*creat_node(char *line)
{
	t_node	*new_node;

	if (!line)
		return (NULL);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->line = ft_strdup(line);
	new_node->next = NULL;
	return (new_node);
}

t_node	*ft_last_node(t_node *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	push_back(t_node **head, t_node *node)
{
	t_node	*last_node;

	if (!head)
		return ;
	if (!*head)
		(*head) = node;
	else
	{
		last_node = ft_last_node(*head);
		last_node->next = node;
	}
}

int	list_size(t_node *map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map)
	{
		i++;
		map = map->next;
	}
	return (i);
}

t_node	*ft_list_at(t_node *begin, int pos)
{
	int	i;

	i = 0;
	if (!begin)
		return (NULL);
	while (begin)
	{
		if (i == pos)
		{
			return (begin);
		}
		i++;
		begin = begin->next;
	}
	return (NULL);
}
