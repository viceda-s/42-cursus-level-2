/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:00:00 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/22 13:59:33 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**create_map_copy(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[game->map_height] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

static void	flood_fill_no_exit(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'E')
		return ;
	map[y][x] = 'V';
	flood_fill_no_exit(map, x + 1, y, game);
	flood_fill_no_exit(map, x - 1, y, game);
	flood_fill_no_exit(map, x, y + 1, game);
	flood_fill_no_exit(map, x, y - 1, game);
}

static int	check_reachable(char **map_copy, t_game *game, char target)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (map_copy[i][j] == target)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_path(t_game *game)
{
	char	**map_copy;
	char	**map_copy2;
	int		result;

	map_copy = create_map_copy(game);
	if (!map_copy)
		return (0);
	flood_fill_no_exit(map_copy, game->player_x, game->player_y, game);
	if (!check_reachable(map_copy, game, 'C'))
	{
		free_map(map_copy);
		return (0);
	}
	free_map(map_copy);
	map_copy2 = create_map_copy(game);
	if (!map_copy2)
		return (0);
	flood_fill(map_copy2, game->player_x, game->player_y, game);
	result = check_reachable(map_copy2, game, 'E');
	free_map(map_copy2);
	return (result);
}
