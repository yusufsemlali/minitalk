/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:43:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/14 14:30:07 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	write_pid(pid_t pid)
{
	char	digits[10];
	int		i;

	i = 0;
	while (pid > 0)
	{
		digits[i] = '0' + (pid % 10);
		pid /= 10;
		i++;
	}
	while (i > 0)
		write(1, &digits[--i], 1);
}

void	handle_signal(int sig, siginfo_t *siginfo, void *context)
{
	static int	i = 0;
	static int	pid;
	static char	c;

	(void)context;
	pid = siginfo->si_pid;
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
				write(1, "Error sending to PID\n", 21);
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	write_pid(pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(1, "Error\n", 6);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(1, "Error\n", 6);
	while (1)
		pause();
	return (0);
}
