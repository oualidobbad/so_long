/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:30 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/22 15:51:08 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_close(t_data *game)
{
	free_list(&game->head);
	free_imgs(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	push_img(t_data *img)
{
	img->caracter = mlx_xpm_file_to_image(img->mlx, "textures/caracter.xpm",
			&img->width_map, &img->height_map);
	img->space = mlx_xpm_file_to_image(img->mlx, "textures/space.xpm",
			&img->width_map, &img->height_map);
	img->wall = mlx_xpm_file_to_image(img->mlx, "textures/wall.xpm",
			&img->width_map, &img->height_map);
	img->collectible = mlx_xpm_file_to_image(img->mlx,
			"textures/collectible.xpm", &img->width_map, &img->height_map);
	img->door = mlx_xpm_file_to_image(img->mlx, "textures/exit.xpm",
			&img->width_map, &img->height_map);
	if (!img->caracter || !img->space || !img->wall || !img->collectible
		|| !img->door)
	{
		write(2, "Error\n", 6);
		handle_close(img);
	}
}

void	put_img_to_window(char c, int i, int j, t_data *img)
{
	if (c == '0')
		mlx_put_image_to_window(img->mlx, img->win, img->space, i * 64, j * 64);
	else if (c == '1')
		mlx_put_image_to_window(img->mlx, img->win, img->wall, i * 64, j * 64);
	else if (c == 'E')
	{
		mlx_put_image_to_window(img->mlx, img->win, img->door, i * 64, j * 64);
		img->colom_exit = i;
		img->row_exit = j;
	}
	else if (c == 'P')
		mlx_put_image_to_window(img->mlx, img->win, img->caracter, i * 64, j
			* 64);
	else if (c == 'C')
		mlx_put_image_to_window(img->mlx, img->win, img->collectible, i * 64, j
			* 64);
}

void	put_img(t_node *map, t_data *img)
{
	int	i;
	int	j;

	j = 0;
	img->height_map = list_size(map);
	push_img(img);
	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			put_img_to_window(map->line[i], i, j, img);
			i++;
		}
		j++;
		map = map->next;
	}
}
