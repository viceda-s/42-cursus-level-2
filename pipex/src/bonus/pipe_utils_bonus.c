/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:20:00 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/07 18:20:00 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

int	**create_pipes(int count)
{
	int	**pipes;
	int	i;

	pipes = malloc(sizeof(int *) * count);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < count)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i] || pipe(pipes[i]) < 0)
		{
			while (i-- > 0)
				free(pipes[i]);
			free(pipes);
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

void	free_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(pipes[i++]);
	free(pipes);
}

int	wait_children(t_pipex *pip)
{
	int	i;
	int	status;
	int	last_status;

	i = 0;
	last_status = 0;
	while (i < pip->cmd_count)
	{
		waitpid(pip->pids[i], &status, 0);
		if (i == pip->cmd_count - 1)
		{
			if (WIFEXITED(status))
				last_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				last_status = 128 + WTERMSIG(status);
		}
		i++;
	}
	return (last_status);
}
