/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:03:19 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/21 19:50:52 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Wrong number of arguments\n", 1);
		exit(1);
	}
	if (init_game(&game) == 0)
		error_exit(&game, "Failed to initialize game");
	load_map(&game, argv[1]);
	find_player_position(&game);
	validate_map(&game);
	if (create_window(&game) == 0)
		error_exit(&game, "Failed to create window");
	find_enemies_positions(&game);
	count_collectibles(&game);
	load_images(&game);
	render_game(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
