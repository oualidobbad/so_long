#include "so_long.h"

void	push_img(t_data *img)
{
	img->caracter = mlx_xpm_file_to_image(img->mlx, "imgs/caracter.xpm", &img->width_map, &img->height_map);
	img->space = mlx_xpm_file_to_image(img->mlx, "imgs/space.xpm", &img->width_map, &img->height_map);
	img->wall = mlx_xpm_file_to_image(img->mlx, "imgs/wall.xpm", &img->width_map, &img->height_map);
	img->collectible = mlx_xpm_file_to_image(img->mlx, "imgs/collectible.xpm", &img->width_map, &img->height_map);
	img->door = mlx_xpm_file_to_image(img->mlx, "imgs/exit.xpm", &img->width_map, &img->height_map);
	if (!img->caracter || !img->space || !img->wall || !img->collectible || !img->door )
		handle_close(img);
}

void put_img_to_window(char c, int i, int j, t_data *img)
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
		mlx_put_image_to_window(img->mlx, img->win, img->caracter, i * 64, j * 64);
	else if (c == 'C')
		mlx_put_image_to_window(img->mlx, img->win, img->collectible, i * 64, j * 64);
}

void put_img(s_node *map, t_data *img)
{
	img->height_map = list_size(map);
	int (i), j = 0;
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
