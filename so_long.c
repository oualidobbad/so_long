#include "so_long.h"
void free_list(s_node **head)
{
	s_node	*temp;

	if (!head)
		return ;
	while (*head)
	{
		free((*head)->line);
		temp = (*head)->next;
		free(*head);
		(*head) = temp;
	}	
}

s_node *read_map()
{
	s_node *map;
	char *line;
	s_node *node;
	int fd;

	map = NULL;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("My Message");
		exit (0);
	}
	while ((line = get_next_line(fd)))
	{
		node = creat_node(line);
		if (!node)
			return (free(line), free_list(&map), perror("Error"), NULL);
		push_back(&map, node);
		free(line);
	}
	close(fd);
	return (map);
}

int main()
{
	s_node *map;
	void *mlx;
	void *mlx_win;

	map = read_map();
	if (!map)
		return (0);
	check_map(map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, lenght_line(map->line) * 64, list_size(map) * 64, "Hello world!");
	put_img(mlx, mlx_win, map);
	mlx_loop(mlx);
	free_list(&map);
	return (0);
}
