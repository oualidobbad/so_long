/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:48:25 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/01 22:47:15 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_exit(t_data *game)
{
	if (game->c <= 0)
	{
		write(1, "move: ", 6);
		ft_putnbr(game->moves++);
		write(1, "\n", 1);
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
}

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
