/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:23:33 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/06 17:27:42 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_split(char **split_result)
{
	int	i;

	if (!split_result)
		return ;
	i = 0;
	while (split_result[i])
	{
		free(split_result[i]);
		i++;
	}
	free(split_result);
}

static char	**parse_args(int ac, char **av)
{
	char	**result;
	int		i;

	if (ac == 2)
		return (ft_split(av[1], ' '));
	i = 0;
	while (++i < ac)
		if (ft_strchr(av[i], ' '))
			return (NULL);
	result = malloc(sizeof(char *) * ac);
	if (!result)
		return (NULL);
	i = 0;
	while (++i < ac)
		result[i - 1] = av[i];
	result[ac - 1] = NULL;
	return (result);
}

static int	process_arg(t_node **a, char *arg)
{
	long	value;

	if (!arg || arg[0] == '\0')
		return (1);
	if (error_syntax(arg))
		return (0);
	value = ft_atol(arg);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	if (error_duplicate(*a, (int)value))
		return (0);
	append_node(a, (int)value);
	return (1);
}

static int	validate_args(t_node **a, char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (!process_arg(a, args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_and_validate(t_node **a, int ac, char **av)
{
	char	**args;
	int		need_free;
	int		result;

	args = parse_args(ac, av);
	if (!args)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	need_free = (ac == 2 && args != av);
	result = validate_args(a, args);
	if (need_free)
		free_split(args);
	else if (args != av)
		free(args);
	if (!result)
		write(2, "Error\n", 6);
	return (result);
}
