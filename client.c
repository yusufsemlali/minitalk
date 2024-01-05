/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:00:48 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/05 22:55:48 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	handle_signal(int sig)
{
	ft_printf("Signal received: %d\n", sig);
	if (sig == SIGUSR2)
	{
		write(1, "message received\n", 17);
		exit(0);
	}
	else
	{
		write(1, " not sigusr2\n", 13);
		exit(1);
	}
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
		signal(SIGUSR2, handle_signal);
		if (send_message(pid, av[2]))
			write(1, "ERROR\n", 6);
		while (1)
			pause();
	}
	write(1, "\n", 1);
	return (0);
}
