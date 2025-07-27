/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:35:02 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/21 19:46:14 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_game_map_and_textures(t_game *game)
{
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->img_width = TILE_SIZE;
	game->img_height = TILE_SIZE;
	game->win = NULL;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player_up = NULL;
	game->img_player_down = NULL;
	game->img_player_left = NULL;
	game->img_player_right = NULL;
	game->img_collectible = NULL;
	game->img_exit = NULL;
	game->img_enemy = NULL;
}

static void	init_game_entities(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->player_direction = DIRECTION_DOWN;
	game->enemies = NULL;
	game->enemy_count = 0;
	game->player_under = '0';
	game->collectibles = 0;
	game->collected = 0;
	game->moves = 0;
}

int	init_game(t_game *game)
{
	if (!game)
		return (0);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	init_game_map_and_textures(game);
	init_game_entities(game);
	return (1);
}

int	create_window(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, window_width, window_height,
			"so_long");
	if (!game->win)
		return (0);
	return (1);
}

void	load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->img_width, &game->img_height);
	game->img_player_up = mlx_xpm_file_to_image(game->mlx,
			"textures/player_up.xpm", &game->img_width, &game->img_height);
	game->img_player_down = mlx_xpm_file_to_image(game->mlx,
			"textures/player_down.xpm", &game->img_width, &game->img_height);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player_left.xpm", &game->img_width, &game->img_height);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right.xpm", &game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->img_width, &game->img_height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "textures/enemy.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_wall || !game->img_floor || !game->img_player_up
		|| !game->img_player_down || !game->img_player_left
		|| !game->img_player_right || !game->img_collectible
		|| !game->img_exit || !game->img_enemy)
		error_exit(game, "Failed to load texture files");
}
