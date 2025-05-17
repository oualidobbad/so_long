#include "/usr/include/minilibx-linux/mlx.h"
#include <stddef.h>
typedef struct data
{
	void *img;
	void *img1;
	void *mlx;
	void *win;

}t_data;

void render(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, 64 , 64);
	mlx_put_image_to_window(data->mlx, data->win, data->img1, 64 * 2, 64);
}
int func(int key, t_data *data)
{
	void *tmp;
	if (key == 'a')
	{
		tmp = data->img;
		data->img = data->img1;
		data->img1 = tmp;
		render(data);
	}
	return 0;
}
int main ()
{
	t_data data;
	int x;
	int y;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 400, 400, "hello");
	data.img = mlx_xpm_file_to_image(data.mlx, "textures/wall.xpm", &x, &y);
	data.img1 = mlx_xpm_file_to_image(data.mlx, "textures/space.xpm",&x, &y);
	render(&data);
    mlx_key_hook(data.win, func, &data);
	mlx_loop(data.mlx);
}
