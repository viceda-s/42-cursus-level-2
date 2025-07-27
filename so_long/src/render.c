/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:06:12 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/18 18:58:22 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	render_map_tile(t_game *game, int x, int y, char tile)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = x * TILE_SIZE;
	pixel_y = y * TILE_SIZE;
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, pixel_x, pixel_y);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, pixel_x, pixel_y);
	else if (tile == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, pixel_x, pixel_y);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, pixel_x, pixel_y);
	}
	else if (tile == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, pixel_x, pixel_y);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collectible, pixel_x, pixel_y);
	}
}

static void	render_player_tile(t_game *game, int x, int y)
{
	int		pixel_x;
	int		pixel_y;
	void	*player_texture;

	pixel_x = x * TILE_SIZE;
	pixel_y = y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_floor, pixel_x, pixel_y);
	if (x == game->player_x && y == game->player_y
		&& game->player_under == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, pixel_x, pixel_y);
	if (game->player_direction == DIRECTION_UP)
		player_texture = game->img_player_up;
	else if (game->player_direction == DIRECTION_DOWN)
		player_texture = game->img_player_down;
	else if (game->player_direction == DIRECTION_LEFT)
		player_texture = game->img_player_left;
	else
		player_texture = game->img_player_right;
	mlx_put_image_to_window(game->mlx, game->win,
		player_texture, pixel_x, pixel_y);
}

static void	render_enemy_tile(t_game *game, int x, int y)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = x * TILE_SIZE;
	pixel_y = y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_floor, pixel_x, pixel_y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy, pixel_x, pixel_y);
}

static void	render_moves_counter(t_game *game)
{
	char	*moves_num;
	char	*moves_str;
	int		bottom_y;

	moves_num = ft_itoa(game->moves);
	moves_str = ft_strjoin("Moves: ", moves_num);
	bottom_y = game->map_height * TILE_SIZE;
	mlx_string_put(game->mlx, game->win, 10, bottom_y, 0xFFFFFF, moves_str);
	free(moves_num);
	free(moves_str);
}

void	render_game(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_map_tile(game, x, y, game->map[y][x]);
			if (game->map[y][x] == 'P')
				render_player_tile(game, x, y);
			else if (game->map[y][x] == 'X')
				render_enemy_tile(game, x, y);
			x++;
		}
		y++;
	}
	render_moves_counter(game);
}
