/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:45:13 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/12 14:08:42 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stddef.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft/include/libft.h"

/* Client functions */
void	send_signal(int pid, unsigned char character);
void	send_string(int pid, char *str);

/* Server functions */
void	handle_signal(int signal);

/* Bonus functions */
void	send_signal_bonus(int pid, unsigned char character);
void	send_string_bonus(int pid, char *str);
void	handle_signal_bonus(int signal, siginfo_t *info, void *context);
void	handle_acknowledgment(int signal);

#endif
