/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:23:41 by viceda-s          #+#    #+#             */
/*   Updated: 2026/01/06 16:09:49 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../inc/push_swap.h"
# include "../libft/include/libft.h"

/* Input Validation */
int		parse_and_validate(t_node **a, int ac, char **av);

/* Command Executor */
int		execute_command(t_node **a, t_node **b, char *cmd);

#endif