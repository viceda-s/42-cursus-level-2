/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:15:18 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/09 17:04:26 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;
	int				i;

	if (stack_len(*a) != 5)
		return ;
	i = 0;
	while (i < 2)
	{
		min_node = find_min(*a);
		while (*a != min_node)
		{
			if (min_node->above_median)
				ra(a, false);
			else
				rra(a, false);
		}
		pb(b, a, false);
		i++;
	}
	sort_three(a);
	pa(a, b, false);
	pa(a, b, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}
