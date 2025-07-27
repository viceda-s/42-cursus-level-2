/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:30:00 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/22 13:59:46 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	collect_item(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->collected++;
		game->map[y][x] = '0';
	}
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	char	original_tile;

	original_tile = game->map[new_y][new_x];
	if (game->player_under == 'E')
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->player_under = original_tile;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

static void	check_victory(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			game->moves++;
			ft_printf("You won! Moves: %d\n", game->moves);
			close_game(game);
		}
		else
		{
			ft_printf("You're at the exit! Collect all items to win! (%d/%d)\n",
				game->collected, game->collectibles);
		}
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
	{
		check_victory(game, new_x, new_y);
		return ;
	}
	if (!is_valid_move(game, new_x, new_y, 0))
		return ;
	collect_item(game, new_x, new_y);
	update_player_position(game, new_x, new_y);
	render_game(game);
	move_enemies(game);
	if (check_collision_with_enemy(game))
	{
		ft_printf("Game Over! Enemy caught you!\n");
		close_game(game);
	}
}
