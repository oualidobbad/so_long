#include "so_long.h"

void	handl_close(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	handle_exit_top_player(t_data *game)
{
	if (game->c == 0)
		exit(0);
}

void	move_player(t_data *game, int i, int j, char move)
{
	//players'coordinates
	int r = game->row;
	int c = game->colom;

	//exit coorrdinates
	int r_e = game->y;
	int c_e = game->x;
	// if (i >= game->height && j >= game->width && i < 1 && j < 0)
	//     return ;
	// if(ft_list_at(game->head, i)->line[j] == '1')
	// 	printf("")
	if (ft_list_at(game->head, i)->line[j] != '1')
	{
		if (r_e == i && j == c_e)
			handle_exit_top_player(game);
		if (ft_list_at(game->head, i)->line[j] == 'C')
			(game->c)--;
		mlx_put_image_to_window(game->mlx, game->win, game->space, c * 64, r
			* 64);
		mlx_put_image_to_window(game->mlx, game->win, game->door, c_e * 64, r_e
			* 64);
		if (move == 's')
			++(game->row);
		else if (move == 'w')
			--(game->row);
		else if (move == 'a')
			--(game->colom);
		else
			++(game->colom);
		mlx_put_image_to_window(game->mlx, game->win, (game->caracter), j * 64, i * 64);
	}
}

int	key_hook(int key_code, t_data *game)
{
	int r, c;
	r = game->row;
	c = game->colom;
	printf("%d ", r);
	printf("%d ", c);
	if (key_code == 65307)
		handl_close(game);
	else if (key_code == 'w')
		move_player(game, r - 1, c, 'w');
	else if (key_code == 's')
		move_player(game, r + 1, c, 's');
	else if (key_code == 'a')
		move_player(game, r, c - 1, 'a');
	else if (key_code == 'd')
		move_player(game, r, c+1, 'd');
	return (0);
}
// 65361
// 65362
// 65363
// 65364