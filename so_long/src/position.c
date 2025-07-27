/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:45:00 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/21 19:51:04 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	count_enemies(t_game *game)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'X')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	allocate_enemies(t_game *game)
{
	if (game->enemy_count > 0)
	{
		game->enemies = malloc(sizeof(t_enemy) * game->enemy_count);
		if (!game->enemies)
			error_exit(game, "Memory allocation failed");
	}
	else
		game->enemies = NULL;
}

static void	store_enemy_positions(t_game *game)
{
	int	y;
	int	x;
	int	enemy_index;

	enemy_index = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'X')
			{
				game->enemies[enemy_index].x = x;
				game->enemies[enemy_index].y = y;
				game->enemies[enemy_index].under = '0';
				enemy_index++;
			}
			x++;
		}
		y++;
	}
}

void	find_enemies_positions(t_game *game)
{
	game->enemy_count = count_enemies(game);
	allocate_enemies(game);
	if (game->enemy_count > 0)
		store_enemy_positions(game);
}
