/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:22:39 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/07 17:24:29 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_cmd(char *cmd, int fd_in, int fd_out, char **env)
{
	char	**args;
	char	*path;

	setup_child_fds(fd_in, fd_out);
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

static int	wait_children(t_pipex *pip)
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

static void	run_pipex(char **av, char **env, t_pipex *pip, int *pfd)
{
	pip->pids[0] = fork();
	if (pip->pids[0] == 0)
	{
		close(pfd[0]);
		free(pip->pids);
		execute_cmd(av[2], pip->fd_in, pfd[1], env);
	}
	pip->pids[1] = fork();
	if (pip->pids[1] == 0)
	{
		close(pfd[1]);
		free(pip->pids);
		execute_cmd(av[3], pfd[0], pip->fd_out, env);
	}
	close(pfd[0]);
	close(pfd[1]);
	close(pip->fd_in);
	close(pip->fd_out);
}

static int	open_files(t_pipex *pip, char **av)
{
	pip->fd_in = open(av[1], O_RDONLY);
	if (pip->fd_in < 0)
		perror(av[1]);
	pip->fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pip->fd_out < 0)
	{
		perror(av[4]);
		if (pip->fd_in >= 0)
			close(pip->fd_in);
		return (1);
	}
	if (pip->fd_in < 0)
		pip->fd_in = open("/dev/null", O_RDONLY);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pip;
	int		pfd[2];
	int		exit_status;

	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", STDERR_FILENO);
		return (1);
	}
	ft_memset(&pip, 0, sizeof(pip));
	if (open_files(&pip, av) != 0)
		return (1);
	if (pipe(pfd) < 0)
		perror("pipe");
	pip.pids = ft_calloc(2, sizeof(pid_t));
	pip.cmd_count = 2;
	run_pipex(av, env, &pip, pfd);
	exit_status = wait_children(&pip);
	free(pip.pids);
	return (exit_status);
}
