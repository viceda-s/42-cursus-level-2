/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:45:39 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/06 17:23:42 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/include/libft.h"

typedef struct s_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_node		*target_node;
	struct s_node		*next;
	struct s_node		*prev;
}	t_node;

//Error handling
int						error_syntax(char *str_n);
int						error_duplicate(t_node *a, int n);
void					free_stack(t_node **stack);
void					free_errors(t_node **a);

//Stack init
void					init_stack_a(t_node **a, char **argv);
char					**split(char *s, char c);

//Node init
void					init_nodes_a(t_node *a, t_node *b);
void					init_nodes_b(t_node *a, t_node *b);
void					current_index(t_node *stack);
void					set_cheapest(t_node *stack);
t_node					*get_cheapest(t_node *stack);
void					prep_for_push(t_node **s, t_node *n, char c);

//Stack utils
long					ft_atol(const char *s);
void					append_node(t_node **stack, int n);
int						stack_len(t_node *stack);
t_node					*find_last(t_node *stack);
bool					stack_sorted(t_node *stack);
t_node					*find_min(t_node *stack);
t_node					*find_max(t_node *stack);

//Sort utils
void					rotate_both(t_node **a, t_node **b,
							t_node *cheapest_node);
void					rev_rotate_both(t_node **a, t_node **b,
							t_node *cheapest_node);
void					move_a_to_b(t_node **a, t_node **b);
void					move_b_to_a(t_node **a, t_node **b);
void					min_on_top(t_node **a);

//Commands
void					sa(t_node **a, bool print);
void					sb(t_node **b, bool print);
void					ss(t_node **a, t_node **b, bool print);
void					ra(t_node **a, bool print);
void					rb(t_node **b, bool print);
void					rr(t_node **a, t_node **b, bool print);
void					rra(t_node **a, bool print);
void					rrb(t_node **b, bool print);
void					rrr(t_node **a, t_node **b, bool print);
void					pa(t_node **a, t_node **b, bool print);
void					pb(t_node **b, t_node **a, bool print);

//Algorithm
void					sort_three(t_node **a);
void					sort_five(t_node **a, t_node **b);
void					sort_stacks(t_node **a, t_node **b);

#endif