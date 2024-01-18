/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:00:48 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/14 14:25:57 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	handle_signal(int sig)
{
	if (sig == SIGUSR2)
		write(1, "Message received by server\n", 27);
	exit(0);
}

int	send_message(int pid, char *message)
{
	int	i;
	int	signal;

	while (1)
	{
		i = 7;
		while (i >= 0)
		{
			signal = SIGUSR2;
			if (((int)*message) & (1 << i))
				signal = SIGUSR1;
			if (kill(pid, signal) == -1)
				return (1);
			i--;
			usleep(250);
		}
		if (*message == '\0')
			break ;
		message++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
	{
		while (*av[1] >= '0' && *av[1] <= '9')
			pid = pid * 10 + (*av[1]++ - '0');
		if (pid <= 0)
		{
			write(1, "Invalid PID\n", 12);
			return (0);
		}
		signal(SIGUSR2, handle_signal);
		if (send_message(pid, av[2]))
		{
			write(1, "Error sending to PID\n", 21);
			return (0);
		}
		while (1)
			pause();
	}
	write(1, "\n", 1);
	return (0);
}
