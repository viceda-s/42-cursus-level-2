/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:54:30 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/07 17:59:39 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

/* bonus-specific functions */
void	handle_here_doc(char *limiter, int *fd_in);
int		**create_pipes(int count);
void	free_pipes(int **pipes, int count);
void	close_pipes(int **pipes, int count);
int		wait_children(t_pipex *pip);
void	execute_pipeline(char **av, char **env, t_pipex *pip, int **pipes);

#endif
