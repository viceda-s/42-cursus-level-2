/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:23:07 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/06 17:19:37 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	process_commands(t_node **a, t_node **b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (!execute_command(a, b, cmd))
		{
			free(cmd);
			write(2, "Error\n", 6);
			return (0);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	return (1);
}

static void	print_result(t_node *a, t_node *b)
{
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!parse_and_validate(&a, ac, av))
	{
		free_stack(&a);
		free_stack(&b);
		return (1);
	}
	if (!process_commands(&a, &b))
	{
		free_stack(&a);
		free_stack(&b);
		return (1);
	}
	print_result(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
