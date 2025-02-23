/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:25 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/23 22:22:44 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_imgs(t_data *game)
{
	if (!game->mlx || !game->win)
		return ;
	if (game->top)
		mlx_destroy_image(game->mlx, game->top);
	if (game->bottom)
		mlx_destroy_image(game->mlx, game->bottom);
	if (game->door)
		mlx_destroy_image(game->mlx, game->door);
	if (game->space)
		mlx_destroy_image(game->mlx, game->space);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->success)
		mlx_destroy_image(game->mlx, game->success);
	if (game->left)
		mlx_destroy_image(game->mlx, game->left);
	if (game->right)
		mlx_destroy_image(game->mlx, game->right);
	if (game->door_open)
		mlx_destroy_image(game->mlx, game->door_open);
	if (game->back_ground_moves)
		mlx_destroy_image(game->mlx, game->back_ground_moves);
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

void 	move_player_with_animation(t_data *game, int i, int j, char move)
{
	if (move == 's')
		{
			++game->row_player;
			mlx_put_image_to_window(game->mlx, game->win, (game->bottom), j * 64, i * 64);
		}
		else if (move == 'w')
		{
			--game->row_player;
			mlx_put_image_to_window(game->mlx, game->win, (game->top), j * 64, i * 64);
		}
		else if (move == 'a')
		{
			--game->colom_player;
			mlx_put_image_to_window(game->mlx, game->win, (game->left), j * 64, i * 64);
		}
		else
		{
			++game->colom_player;
			mlx_put_image_to_window(game->mlx, game->win, (game->right), j * 64, i * 64);
		}
}

void	move_player_helper(t_data *game, int i, int j, char move)
{
	if (game->c <= 0 && game->succ == 0)
	{
		if (move == 's')
			++game->row_player;
		else if (move == 'w')
			--game->row_player;
		else if (move == 'a')
			--game->colom_player;
		else
			++game->colom_player;
		game->succ++;
		mlx_put_image_to_window(game->mlx, game->win, (game->success), j * 64, i * 64);
	}
	else
		move_player_with_animation(game, i, j, move);
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
		if (game->c <= 0)
			mlx_put_image_to_window(game->mlx, game->win, game->door_open,
				game->colom_exit * 64, game->row_exit * 64);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->door,
				game->colom_exit * 64, game->row_exit * 64);
		move_player_helper(game, i, j, move);
		mlx_put_image_to_window(game->mlx, game->win, game->back_ground_moves, 0, 0);
		game->str = ft_itoa(game->moves++);
		mlx_string_put(game->mlx, game->win, 10, 30, 0x000000, "moves:");
		mlx_string_put(game->mlx, game->win,80 , 30, 0x000000, game->str);
		free (game->str);
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
