/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:15:18 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/06 17:24:06 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

static void	move_min_to_top(t_node **a)
{
	t_node	*min_node;
	t_node	*current;
	int		min_pos;
	int		len;

	min_node = find_min(*a);
	min_pos = 0;
	len = stack_len(*a);
	current = *a;
	while (current != min_node)
	{
		min_pos++;
		current = current->next;
	}
	if (min_pos <= len / 2)
	{
		while (min_pos-- > 0)
			ra(a, false);
	}
	else
	{
		while (min_pos++ < len)
			rra(a, false);
	}
}

void	sort_five(t_node **a, t_node **b)
{
	if (stack_len(*a) != 5)
		return ;
	move_min_to_top(a);
	pb(b, a, false);
	move_min_to_top(a);
	pb(b, a, false);
	sort_three(a);
	pa(a, b, false);
	pa(a, b, false);
}
