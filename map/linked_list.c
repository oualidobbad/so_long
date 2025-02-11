#include "../so_long.h"

s_node	*creat_node(char *line)
{
	s_node	*new_node;

	if (!line)
		return (NULL);
	new_node = malloc(sizeof(s_node));
	if (!new_node)
		return (NULL);
	new_node->line = ft_strdup(line);
	new_node->next = NULL;
	return (new_node);
}

s_node	*ft_last_node(s_node *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	push_back(s_node **head, s_node *node)
{
	s_node *last_node;

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
int	list_size(s_node *map)
{
	int i;

	i = 0;
	if (!map)
		return 0;
	while (map)
	{
		i++;
		map = map->next;
	}
	return i;
}

s_node	*ft_list_at(s_node *begin, int pos)
{
	int	i;

	i = 1;
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

