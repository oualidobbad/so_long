#include "so_long.h"

int check_ber (char *str, char *ber)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			while (str[i + j] && str[i + j] == ber[j])
			{
				j++;
			}
			if (ber[j] == '\0')
				return 1;
		}
		i++;
	}
	return 0;
}
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

s_node *read_map(char *av)
{
	s_node *map;
	char *line;
	s_node *node;
	int fd;

	map = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		perror("My Message");
		exit (0);
	}
	while ((line = get_next_line(fd)))
	{
		node = creat_node(line);
		if (!node)
			return (free(line), free_list(&map), NULL);
		push_back(&map, node);
		free(line);
	}
	close(fd);
	return (map);
}

int main(int ac, char **av)
{
	t_data game;

	if (ac != 2 || check_ber(av[1], ".ber") == 0)
		return 1;
	game.head = read_map(av[1]);
	if (!game.head)
		return (1);
	check_map(&game, game.head);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, lenght_line(game.head->line) * 64, list_size(game.head) * 64, "Hello world!");
	put_img(game.head, &game);
	game.height_map =  list_size(game.head);
	game.width_map =  lenght_line(game.head->line);
	game.moves = 1;
	mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
	mlx_hook(game.win, 17, 1L<<17, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
