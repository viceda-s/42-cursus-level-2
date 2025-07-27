/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:55:50 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/21 19:46:32 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (i < game->map_height)
	{
		len = ft_strlen(game->map[i]);
		if (len != game->map_width)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1'
			|| game->map[game->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < game->map_height)
	{
		if (game->map[j][0] != '1'
			|| game->map[j][game->map_width - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_valid_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_required_elements(t_game *game)
{
	int	i;
	int	j;
	int	player_count;
	int	exit_count;
	int	collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	i = -1;
	while (++i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
				player_count++;
			else if (game->map[i][j] == 'E')
				exit_count++;
			else if (game->map[i][j] == 'C')
				collectible_count++;
			j++;
		}
	}
	return (player_count == 1 && exit_count == 1 && collectible_count >= 1);
}

int	validate_map(t_game *game)
{
	if (!check_rectangular(game))
		error_exit(game, "Map is not rectangular");
	if (!check_walls(game))
		error_exit(game, "Map is not surrounded by walls");
	if (!check_required_elements(game))
		error_exit(game, "Map missing required elements");
	if (!check_valid_characters(game))
		error_exit(game, "Map contains invalid characters");
	if (!validate_path(game))
		error_exit(game, "No valid path to collect all items and reach exit");
	return (1);
}
