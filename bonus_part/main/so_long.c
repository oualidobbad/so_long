/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:19 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/27 22:17:01 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	return_coordinates(t_node *map, t_data *coordinates)
{
	int	i;
	int	j;

	j = 0;
	coordinates->colom_player = 0;
	coordinates->row_player = 0;
	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == 'P')
			{
				coordinates->colom_player = i;
				coordinates->row_player = j;
				return ;
			}
			i++;
		}
		j++;
		map = map->next;
	}
}

int	check_ber(char *str, char *ber)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			while (str[i + j] && str[i + j] == ber[j])
				j++;
			if (ber[j] == '\0')
				return (1);
		}
		i++;
	}
	return (perror("Error\nFile Not end with .ber"), 0);
}

void	free_list(t_node **head)
{
	t_node	*temp;

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

t_node	*read_map(char *av)
{
	t_node	*map;
	char	*line;
	t_node	*node;
	int		fd;

	map = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(0);
	}
	line = get_next_line(fd);
	while (line)
	{
		node = creat_node(line);
		if (!node)
			return (free(line), free_list(&map), NULL);
		push_back(&map, node);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2 || check_ber(av[1], ".ber") == 0)
		return (1);
	game.head = read_map(av[1]);
	if (!game.head)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	check_map(&game, game.head);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, lenght_line(game.head->line) * 64,
			list_size(game.head) * 64, "so_long");
	put_img(game.head, &game);
	game.height_map = list_size(game.head);
	game.width_map = lenght_line(game.head->line);
	game.moves = 1;
	game.succ = 0;
	mlx_set_font(game.mlx, game.win, "12*24");
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
