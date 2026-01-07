/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:20:00 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/07 18:20:00 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	execute_cmd(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		exit(127);
	path = find_cmd_path(args[0], env);
	if (!path)
		command_not_found(args[0], args);
	execve(path, args, env);
	perror("execve");
	free_split(args);
	free(path);
	exit(126);
}

static void	setup_child_io(t_pipex *pip, int **pipes, int i)
{
	if (i == 0)
		dup2(pip->fd_in, STDIN_FILENO);
	else
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i == pip->cmd_count - 1)
		dup2(pip->fd_out, STDOUT_FILENO);
	else
		dup2(pipes[i][1], STDOUT_FILENO);
	close_pipes(pipes, pip->cmd_count - 1);
	close(pip->fd_in);
	close(pip->fd_out);
}

void	execute_pipeline(char **av, char **env, t_pipex *pip, int **pipes)
{
	int	i;
	int	cmd_start;

	cmd_start = 2 + pip->here_doc;
	i = 0;
	while (i < pip->cmd_count)
	{
		pip->pids[i] = fork();
		if (pip->pids[i] == 0)
		{
			setup_child_io(pip, pipes, i);
			free(pip->pids);
			execute_cmd(av[cmd_start + i], env);
		}
		i++;
	}
}
