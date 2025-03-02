/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:30 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/02 14:27:58 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	handle_error_imags(t_data *img)
{
	if (!img->enimy || !img->back_ground_moves || !img->bottom || !img->top
		|| !img->space || !img->wall || !img->collectible || !img->door
		|| !img->left || !img->right || !img->success || !img->door_open)
	{
		write(2, "Error\n", 6);
		handle_close(img);
	}
}

void	push_img(t_data *img)
{
	img->top = mlx_xpm_file_to_image(img->mlx, "textures/top.xpm",
			&img->width_map, &img->height_map);
	img->bottom = mlx_xpm_file_to_image(img->mlx, "textures/bottom.xpm",
			&img->width_map, &img->height_map);
	img->success = mlx_xpm_file_to_image(img->mlx, "textures/happy.xpm",
			&img->width_map, &img->height_map);
	img->left = mlx_xpm_file_to_image(img->mlx, "textures/left.xpm",
			&img->width_map, &img->height_map);
	img->right = mlx_xpm_file_to_image(img->mlx, "textures/right.xpm",
			&img->width_map, &img->height_map);
	img->space = mlx_xpm_file_to_image(img->mlx, "textures/space.xpm",
			&img->width_map, &img->height_map);
	img->wall = mlx_xpm_file_to_image(img->mlx, "textures/wall.xpm",
			&img->width_map, &img->height_map);
	img->collectible = mlx_xpm_file_to_image(img->mlx,
			"textures/collectible.xpm", &img->width_map, &img->height_map);
	img->door = mlx_xpm_file_to_image(img->mlx, "textures/door.xpm",
			&img->width_map, &img->height_map);
	img->door_open = mlx_xpm_file_to_image(img->mlx, "textures/door_open.xpm",
			&img->width_map, &img->height_map);
	img->back_ground_moves = mlx_xpm_file_to_image(img->mlx,
			"textures/black.xpm", &img->width_map, &img->height_map);
	img->enimy = mlx_xpm_file_to_image(img->mlx, "textures/enimy.xpm",
			&img->width_map, &img->height_map);
	handle_error_imags(img);
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
		mlx_put_image_to_window(img->mlx, img->win, img->top, i * 64, j * 64);
	else if (c == 'C')
		mlx_put_image_to_window(img->mlx, img->win, img->collectible, i * 64, j
			* 64);
	else
		mlx_put_image_to_window(img->mlx, img->win, img->enimy, i * 64, j * 64);
}

void	put_img(t_node *map, t_data *img)
{
	int	i;
	int	j;

	j = 0;
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
