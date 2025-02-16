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
	t_data game;

	game.height_map = 0;
	game.width_map = 0;

	game.head = read_map();
	if (!game.head)
		return (0);
	
	check_map(&game, game.head);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, lenght_line(game.head->line) * 64, list_size(game.head) * 64, "Hello world!");
	return_coordinates(game.head, &game.row_player, &game.colom_player);
	put_img(game.mlx, game.win, game.head, &game);
	game.height_map =  list_size(game.head);
	game.width_map =  lenght_line(game.head->line);
	mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
