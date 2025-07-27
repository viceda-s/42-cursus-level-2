/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:30:00 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/19 12:53:50 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_collision_with_enemy(t_game *game)
{
	int	i;

	if (!game->enemies || game->enemy_count == 0)
		return (0);
	i = 0;
	while (i < game->enemy_count)
	{
		if (game->player_x == game->enemies[i].x
			&& game->player_y == game->enemies[i].y)
			return (1);
		i++;
	}
	return (0);
}

void	check_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			ft_printf("You won! Moves: %d\n", game->moves + 1);
			close_game(game);
		}
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_game(game);
	else if (keycode == W_KEY || keycode == 65362)
	{
		game->player_direction = DIRECTION_UP;
		move_player(game, game->player_x, game->player_y - 1);
	}
	else if (keycode == S_KEY || keycode == 65364)
	{
		game->player_direction = DIRECTION_DOWN;
		move_player(game, game->player_x, game->player_y + 1);
	}
	else if (keycode == A_KEY || keycode == 65361)
	{
		game->player_direction = DIRECTION_LEFT;
		move_player(game, game->player_x - 1, game->player_y);
	}
	else if (keycode == D_KEY || keycode == 65363)
	{
		game->player_direction = DIRECTION_RIGHT;
		move_player(game, game->player_x + 1, game->player_y);
	}
	return (0);
}

int	is_valid_move(t_game *game, int new_x, int new_y, int is_enemy)
{
	int	i;

	if (new_x < 0 || new_x >= game->map_width)
		return (0);
	if (new_y < 0 || new_y >= game->map_height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'E')
		return (0);
	if (is_enemy && new_x == game->player_x && new_y == game->player_y)
		return (0);
	if (is_enemy && game->enemies)
	{
		i = 0;
		while (i < game->enemy_count)
		{
			if (game->enemies[i].x == new_x && game->enemies[i].y == new_y)
				return (0);
			i++;
		}
	}
	return (1);
}

void	count_collectibles(t_game *game)
{
	int	y;
	int	x;

	game->collectibles = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			x++;
		}
		y++;
	}
}
