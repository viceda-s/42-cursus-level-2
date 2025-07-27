/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:53:54 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/21 19:45:47 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/include/libft.h"
# include <fcntl.h>

# define TILE_SIZE 32
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define DIRECTION_UP 0
# define DIRECTION_DOWN 1
# define DIRECTION_LEFT 2
# define DIRECTION_RIGHT 3

typedef struct s_enemy
{
	int		x;
	int		y;
	char	under;
}	t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_collectible;
	void	*img_exit;
	void	*img_floor;
	void	*img_player_up;
	void	*img_player_down;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_wall;
	void	*img_enemy;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		player_direction;
	t_enemy	*enemies;
	int		enemy_count;
	char	player_under;
	int		collectibles;
	int		collected;
	int		moves;
	int		img_width;
	int		img_height;
}	t_game;

// Function prototypes
// init.c
int		init_game(t_game *game);
int		create_window(t_game *game);
void	load_images(t_game *game);

// position.c
void	find_player_position(t_game *game);
void	find_enemies_positions(t_game *game);

// map_loader.c
int		load_map(t_game *game, char *filename);

// map_validator.c
int		validate_map(t_game *game);

// path_validator.c
int		validate_path(t_game *game);
int		check_path_validation(t_game *game);

// render.c
void	render_game(t_game *game);

// player.c
void	move_player(t_game *game, int new_x, int new_y);

// enemy.c
void	move_enemies(t_game *game);

// game_logic.c
int		check_collision_with_enemy(t_game *game);
void	check_exit(t_game *game, int x, int y);
int		handle_keypress(int keycode, t_game *game);
void	count_collectibles(t_game *game);

// moves.c
int		is_valid_move(t_game *game, int new_x, int new_y, int is_enemy);

// cleanup.c
void	error_exit(t_game *game, char *specific_msg);
void	cleanup_partial_game(t_game *game);
void	free_map(char **map);
int		close_game(t_game *game);
int		check_required_elements(t_game *game);

#endif