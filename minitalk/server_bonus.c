/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:45:00 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/14 07:38:10 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_acknowledgment(pid_t client_pid)
{
	if (kill(client_pid, SIGUSR1) == -1)
	{
		ft_putstr_fd("Error: Failed to send acknowledgment\n", 2);
		exit(1);
	}
}

void	handle_signal_bonus(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_index;
	static pid_t			client_pid;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			write(1, "\n", 1);
			client_pid = 0;
		}
		else
			write(1, &current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	send_acknowledgment(info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_putstr_fd("Server Bonus PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Waiting for messages...\n", 1);
	sa.sa_sigaction = handle_signal_bonus;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: Failed to set signal handler\n", 2);
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: Failed to set signal handler\n", 2);
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
