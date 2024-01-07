/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:00:48 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/07 00:19:32 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"


void	handle_signal(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message received\n");
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
			usleep(200);
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
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_printf("PID ERROR\n");
			return (0);
		}
		signal(SIGUSR2, handle_signal);
		if (send_message(pid, av[2]))
		{
			ft_printf("Error sending to pid %d\n", pid);
			exit(0);
		}
		while (1)
			pause();
	}
	write(1, "\n", 1);
	return (0);
}
