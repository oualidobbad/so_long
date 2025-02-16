#include "so_long.h"

void	push_img(void *mlx, t_data *img, s_node *map)
{
	img->caracter = mlx_xpm_file_to_image(mlx, "imgs/caracter.xpm", &img->width, &img->height);
	img->space = mlx_xpm_file_to_image(mlx, "imgs/space.xpm", &img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(mlx, "imgs/wall.xpm", &img->width, &img->height);
	img->collectible = mlx_xpm_file_to_image(mlx, "imgs/collectible.xpm", &img->width, &img->height);
	img->door = mlx_xpm_file_to_image(mlx, "imgs/exit.xpm", &img->width, &img->height);
}
void put_img(void *mlx,void *win_mlx, s_node *map, t_data *img)
{
	img->height = list_size(map);
	int (i), j = 0;
	push_img(mlx, img, map);
	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == '0')
				mlx_put_image_to_window(mlx, win_mlx, img->space, i * 64, j * 64);
			else if (map->line[i] == '1')
				mlx_put_image_to_window(mlx, win_mlx, img->wall, i * 64, j * 64);
			else if (map->line[i] == 'E')
			{
				mlx_put_image_to_window(mlx, win_mlx, img->door, i * 64, j * 64);
				img->x = i;
				img->y = j;
			}
			else if (map->line[i] == 'P')
				mlx_put_image_to_window(mlx, win_mlx, img->caracter, i * 64, j * 64);
			else if (map->line[i] == 'C')
				mlx_put_image_to_window(mlx, win_mlx, img->collectible, i * 64, j * 64);
			i++;
		}
		j++;
		map = map->next;
	}
}
