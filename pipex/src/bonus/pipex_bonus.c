/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:00:00 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/07 18:18:29 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	open_output_file(t_pipex *pip, char *filename, int append)
{
	if (append)
		pip->fd_out = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pip->fd_out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pip->fd_out < 0)
	{
		perror(filename);
		if (pip->fd_in >= 0)
			close(pip->fd_in);
		return (1);
	}
	return (0);
}

static int	open_files(t_pipex *pip, char **av, int ac)
{
	if (pip->here_doc)
	{
		handle_here_doc(av[2], &pip->fd_in);
		if (open_output_file(pip, av[ac - 1], 1) != 0)
			return (1);
	}
	else
	{
		pip->fd_in = open(av[1], O_RDONLY);
		if (pip->fd_in < 0)
			perror(av[1]);
		if (open_output_file(pip, av[ac - 1], 0) != 0)
			return (1);
	}
	if (pip->fd_in < 0)
		pip->fd_in = open("/dev/null", O_RDONLY);
	return (0);
}

static void	run_pipex(char **av, char **env, t_pipex *pip, int **pipes)
{
	execute_pipeline(av, env, pip, pipes);
	close_pipes(pipes, pip->cmd_count - 1);
	close(pip->fd_in);
	close(pip->fd_out);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pip;
	int		**pipes;
	int		exit_status;

	ft_memset(&pip, 0, sizeof(pip));
	if (ac < 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2\n", 2);
		ft_putstr_fd("   or: ./pipex here_doc LIMITER cmd1 cmd2 file\n", 2);
		return (1);
	}
	pip.here_doc = (ft_strncmp(av[1], "here_doc", 9) == 0);
	pip.cmd_count = ac - 3 - pip.here_doc;
	if (open_files(&pip, av, ac) != 0)
		return (1);
	pipes = create_pipes(pip.cmd_count - 1);
	if (!pipes)
		return (perror("pipe"), 1);
	pip.pids = ft_calloc(pip.cmd_count, sizeof(pid_t));
	run_pipex(av, env, &pip, pipes);
	exit_status = wait_children(&pip);
	free(pip.pids);
	free_pipes(pipes, pip.cmd_count - 1);
	return (exit_status);
}
