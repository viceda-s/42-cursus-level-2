/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:54:30 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/07 17:21:43 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	pid_t	*pids;
	int		cmd_count;
	int		here_doc;
}	t_pipex;

/* path */
char	*find_cmd_path(char *cmd, char **env);

/* utils */
void	free_split(char **split);
char	*free_strjoin(char *s1, char *s2);
void	setup_child_fds(int fd_in, int fd_out);
void	command_not_found(char *cmd, char **args);

#endif