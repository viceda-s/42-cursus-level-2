/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:45:00 by viceda-s          #+#    #+#             */
/*   Updated: 2025/07/14 07:45:56 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_received = 0;

void	handle_acknowledgment(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
}

void	send_signal_bonus(int pid, unsigned char character)
{
	int	i;
	int	bit;
	int	signal_type;

	i = 7;
	while (i >= 0)
	{
		bit = (character >> i) & 1;
		if (bit)
			signal_type = SIGUSR1;
		else
			signal_type = SIGUSR2;
		if (kill(pid, signal_type) == -1)
		{
			ft_putstr_fd("Error: Failed to send signal\n", 2);
			exit(1);
		}
		while (!g_received)
			usleep(400);
		g_received = 0;
		i--;
	}
}

void	send_string_bonus(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signal_bonus(pid, str[i]);
		i++;
	}
	send_signal_bonus(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client_bonus <PID> <message>\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 1);
		return (1);
	}
	signal(SIGUSR1, handle_acknowledgment);
	ft_putstr_fd("Sending message to server...\n", 1);
	send_string_bonus(pid, argv[2]);
	ft_putstr_fd("Message sent successfully!\n", 1);
	return (0);
}
