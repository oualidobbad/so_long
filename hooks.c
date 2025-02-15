#include "so_long.h"
void handl_close(t_data *game) 
{
	
    mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

void	moves_right(t_data *game)
{
	s_node *content_row;

	return_coordinates(game->head, &game->row, &game->colom);
	content_row = ft_list_at(game->head, game->row);
	if (content_row->line[game->colom + 1] != '1')
	{
		content_row->line[game->colom] = '0';
		content_row->line[game->colom + 1] = 'P';
		put_img(game->mlx, game->win, game->head);
	}
}
void	moves_left(t_data *game)
{
	s_node *content_row;

	return_coordinates(game->head, &game->row, &game->colom);
	content_row = ft_list_at(game->head, game->row);
	if (content_row->line[game->colom - 1] != '1')
	{
		content_row->line[game->colom] = '0';
		content_row->line[game->colom - 1] = 'P';
		put_img(game->mlx, game->win, game->head);
	}
}
void	move_top(t_data *game)
{
	s_node *content_row;

	return_coordinates(game->head, &game->row, &game->colom);
	content_row = ft_list_at(game->head, game->row - 1);
	if (content_row->line[game->colom] != '1')
	{
		content_row->line[game->colom] = 'P';
		content_row->next->line[game->colom] = '0';
		put_img(game->mlx, game->win, game->head);
	}
}

void move_bottom(t_data *game)
{
	s_node *content_row;

	return_coordinates(game->head, &game->row, &game->colom);
	content_row = ft_list_at(game->head, game->row);
	if (content_row->next->line[game->colom] != '1')
	{
		content_row->line[game->colom] = '0';
		content_row->next->line[game->colom] = 'P';
		put_img(game->mlx, game->win, game->head);
	}
}
int key_hook(int key_code, t_data *game)
{
	int x;
	int y;

	if (key_code == 65307)
		handl_close(game);
	else if (key_code == 65363)
		moves_right(game);
	else if (key_code == 65361)
		moves_left(game);
	else if (key_code == 65362)
		move_top(game);
	else if (key_code == 65364)
	 move_bottom(game);
	return (printf ("%d\n", key_code));
}
// 65361
// 65362
// 65363
// 65364