/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:18:15 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/22 13:57:01 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_lines_and_allocate(t_game *game, char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		lines++;
	}
	close(fd);
	game->map_height = lines;
	if (lines <= 0)
		return (0);
	game->map = malloc(sizeof(char *) * (lines + 1));
	if (!game->map)
		return (0);
	game->map[lines] = NULL;
	return (1);
}

static char	*clean_line(char *line)
{
	int	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static int	validate_and_open_file(char *filename, t_game *game)
{
	int	fd;
	int	len;

	if (!filename)
		return (-1);
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		free(game->map);
		game->map = NULL;
		error_exit(game, "Invalid file extension (must be .ber)");
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(game->map);
		game->map = NULL;
		error_exit(game, "Permission denied or file not found");
	}
	return (fd);
}

static int	read_map_content(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			while (--i >= 0)
				free(game->map[i]);
			free(game->map);
			game->map = NULL;
			return (0);
		}
		line = clean_line(line);
		game->map[i] = line;
		if (i == 0)
			game->map_width = ft_strlen(line);
		i++;
	}
	return (1);
}

int	load_map(t_game *game, char *filename)
{
	int	fd;

	if (!count_lines_and_allocate(game, filename))
		error_exit(game, "Map file not found or empty");
	fd = validate_and_open_file(filename, game);
	if (!read_map_content(game, fd))
	{
		close(fd);
		error_exit(game, "Failed to read map content");
	}
	close(fd);
	return (1);
}
