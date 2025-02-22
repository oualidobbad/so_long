/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:25 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/22 17:07:17 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_imgs(t_data *game)
{
	if (!game->mlx || !game->win)
		return ;
	if (game->caracter)
		mlx_destroy_image(game->mlx, game->caracter);
	if (game->door)
		mlx_destroy_image(game->mlx, game->door);
	if (game->space)
		mlx_destroy_image(game->mlx, game->space);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
}

void	handle_exit(t_data *game)
{
	if (game->c <= 0)
	{
		free_list(&game->head);
		free_imgs(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
}

void	move_player_helper(t_data *game, int i, int j, char move)
{
	if (move == 's')
		++game->row_player;
	else if (move == 'w')
		--game->row_player;
	else if (move == 'a')
		--game->colom_player;
	else
		++game->colom_player;
	mlx_put_image_to_window(game->mlx, game->win, (game->caracter), j * 64, i
		* 64);
}

void	move_player(t_data *game, int i, int j, char move)
{
	if (i > game->height_map && j >= game->width_map && i < 1 && j < 0)
		return ;
	if (ft_list_at(game->head, i)->line[j] != '1')
	{
		if (game->row_exit == i && j == game->colom_exit)
			handle_exit(game);
		if (ft_list_at(game->head, i)->line[j] == 'C')
		{
			ft_list_at(game->head, i)->line[j] = '0';
			game->c--;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->space,
			game->colom_player * 64, game->row_player * 64);
		mlx_put_image_to_window(game->mlx, game->win, game->door,
			game->colom_exit * 64, game->row_exit * 64);
		move_player_helper(game, i, j, move);
		write (1, "move: ", 6);
		ft_putnbr(game->moves++);
		write (1, "\n", 1);
	}
}

int	key_hook(int key_code, t_data *game)
{
	int	r;
	int	c;

	r = game->row_player;
	c = game->colom_player;
	if (key_code == 65307)
		handle_close(game);
	else if (key_code == 'w')
		move_player(game, r - 1, c, 'w');
	else if (key_code == 's')
		move_player(game, r + 1, c, 's');
	else if (key_code == 'a')
		move_player(game, r, c - 1, 'a');
	else if (key_code == 'd')
		move_player(game, r, c + 1, 'd');
	return (0);
}
