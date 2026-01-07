/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:25:29 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/07 17:22:00 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	*free_strjoin(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

void	setup_child_fds(int fd_in, int fd_out)
{
	if (dup2(fd_in, STDIN_FILENO) < 0 || dup2(fd_out, STDOUT_FILENO) < 0)
	{
		perror("dup2");
		exit(1);
	}
	close(fd_in);
	close(fd_out);
}

void	command_not_found(char *cmd, char **args)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	free_split(args);
	exit(127);
}
