/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:43:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/05 22:55:46 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	handle_signal(int sig, siginfo_t *siginfo, void *context)
{
	static int	i = 0;
	static int	pid;
	static char	c;

	(void)context;
	pid = siginfo->si_pid;
	if (i == 0)
		c = 0;
	c <<= 1;
	if (sig == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if ((int)c == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_printf("Error sending to pid %d\n", pid);
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error\n");
	sigaction(SIGTERM, &sa, NULL);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error\n");
	while (1)
		pause();
	return (0);
}
