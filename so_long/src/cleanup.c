/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:50:00 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/21 19:46:20 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cleanup_partial_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->enemies)
		free(game->enemies);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	get_next_line(-42);
}

void	error_exit(t_game *game, char *specific_msg)
{
	cleanup_partial_game(game);
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(specific_msg, 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	destroy_images(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player_up)
		mlx_destroy_image(game->mlx, game->img_player_up);
	if (game->img_player_down)
		mlx_destroy_image(game->mlx, game->img_player_down);
	if (game->img_player_left)
		mlx_destroy_image(game->mlx, game->img_player_left);
	if (game->img_player_right)
		mlx_destroy_image(game->mlx, game->img_player_right);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
}

int	close_game(t_game *game)
{
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		free_map(game->map);
	if (game->enemies)
		free(game->enemies);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	get_next_line(-42);
	exit(0);
	return (0);
}
