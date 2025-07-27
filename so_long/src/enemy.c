/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:30:00 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/19 12:52:57 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	calculate_enemy_direction(t_game *game, t_enemy *enemy,
	int *dx, int *dy)
{
	*dx = 0;
	*dy = 0;
	if (game->player_x > enemy->x)
		*dx = 1;
	else if (game->player_x < enemy->x)
		*dx = -1;
	if (game->player_y > enemy->y)
		*dy = 1;
	else if (game->player_y < enemy->y)
		*dy = -1;
}

static void	update_enemy_position(t_game *game, t_enemy *enemy,
	int new_x, int new_y)
{
	char	new_cell_content;

	new_cell_content = game->map[new_y][new_x];
	game->map[enemy->y][enemy->x] = enemy->under;
	enemy->x = new_x;
	enemy->y = new_y;
	enemy->under = new_cell_content;
	game->map[new_y][new_x] = 'X';
}

static int	try_move_direction(t_game *game, t_enemy *enemy, int dx, int dy)
{
	int	new_x;
	int	new_y;

	if (dx != 0)
	{
		new_x = enemy->x + dx;
		new_y = enemy->y;
	}
	else if (dy != 0)
	{
		new_x = enemy->x;
		new_y = enemy->y + dy;
	}
	else
		return (0);
	if (is_valid_move(game, new_x, new_y, 1))
	{
		update_enemy_position(game, enemy, new_x, new_y);
		return (1);
	}
	return (0);
}

static void	move_single_enemy(t_game *game, t_enemy *enemy)
{
	int	dx;
	int	dy;

	calculate_enemy_direction(game, enemy, &dx, &dy);
	if (try_move_direction(game, enemy, dx, 0))
		return ;
	if (try_move_direction(game, enemy, 0, dy))
		return ;
}

void	move_enemies(t_game *game)
{
	int	i;

	if (!game->enemies || game->enemy_count == 0)
		return ;
	i = 0;
	while (i < game->enemy_count)
	{
		move_single_enemy(game, &game->enemies[i]);
		i++;
	}
}
