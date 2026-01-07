/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:48:47 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/07 17:02:40 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path_env(char **env)
{
	while (env && **env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

static char	*try_path(char *path_dir, char *cmd)
{
	char	*full_path;
	char	*temp;

	temp = ft_strjoin(path_dir, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	if (!full_path)
		return (NULL);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **env)
{
	char	**path;
	char	*result;
	int		i;

	if (!cmd || !*cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	path = ft_split(get_path_env(env), ':');
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		result = try_path(path[i], cmd);
		if (result)
		{
			free_split(path);
			return (result);
		}
		i++;
	}
	free_split(path);
	return (NULL);
}
