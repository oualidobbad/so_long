#include "../so_long.h"

s_node *map_copy(s_node *map)
{
	s_node *map_copy;
	s_node *node;

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
