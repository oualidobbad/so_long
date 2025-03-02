/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:57:13 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/02 14:28:07 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

void	free_imgs_help(t_data *game)
{
	if (game->right)
		mlx_destroy_image(game->mlx, game->right);
	if (game->door_open)
		mlx_destroy_image(game->mlx, game->door_open);
	if (game->back_ground_moves)
		mlx_destroy_image(game->mlx, game->back_ground_moves);
	if (game->enimy)
		mlx_destroy_image(game->mlx, game->enimy);
}

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
	free_imgs_help(game);
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
