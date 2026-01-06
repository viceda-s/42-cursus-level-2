/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:32:00 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/06 15:55:35 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	execute_swap_commands(t_node **a, t_node **b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(a, true);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(b, true);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(a, b, true);
	else
		return (0);
	return (1);
}

static int	execute_push_commands(t_node **a, t_node **b, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(a, b, true);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(b, a, true);
	else
		return (0);
	return (1);
}

static int	execute_rotate_commands(t_node **a, t_node **b, char *cmd)
{
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(a, true);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(b, true);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(a, b, true);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(a, true);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(b, true);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(a, b, true);
	else
		return (0);
	return (1);
}

int	execute_command(t_node **a, t_node **b, char *cmd)
{
	if (!cmd || cmd[0] == '\n')
		return (1);
	if (execute_swap_commands(a, b, cmd))
		return (1);
	if (execute_push_commands(a, b, cmd))
		return (1);
	if (execute_rotate_commands(a, b, cmd))
		return (1);
	return (0);
}
