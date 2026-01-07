/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:00:00 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/07 18:00:00 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_here_doc(char *limiter, int *fd_in)
{
	int		pfd[2];
	char	*line;

	if (pipe(pfd) < 0)
	{
		perror("pipe");
		exit(1);
	}
	ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pfd[1]);
		free(line);
		ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
	}
	close(pfd[1]);
	*fd_in = pfd[0];
}
