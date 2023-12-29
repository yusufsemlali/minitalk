/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:00:48 by ysemlali          #+#    #+#             */
/*   Updated: 2023/12/29 21:32:34 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

char	*ft_valid_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (pid[i] < '0' || pid[i] > '9')
		{
			write(1, "INVALID PID\n", 12);
			exit(0);
		}
		i++;
	}
	return (pid);
}

char	*ascii_to_binary(int ascii)
{
	char	*binary;
	int		i;

	i = 7;
	binary = malloc(9);
	if (!binary)
		return (NULL);
	while (i >= 0)
	{
		if (ascii & (1 << i))
			binary[7 - i] = '1';
		else
			binary[7 - i] = '0';
		i--;
	}
	binary[8] = '\0';
	return (binary);
}

void	receive_signal(int pid, char *message)
{
	int		i;
	char	*binary;
	int		signal;
	int		j;

	i = 0;
	while (message[i] != '\0')
	{
		binary = ascii_to_binary((int)message[i++]);
		j = 0;
		while (binary[j] != '\0')
		{
			signal = SIGUSR2;
			if (binary[j] == '1')
				signal = SIGUSR1;
			if (kill(pid, signal) == -1)
			{
				write(1, "error", 5);
				free(binary);
				return ;
			}
			j++;
			usleep(210);
		}
		free(binary);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
	{
		printf("%i", getuid());
		pid = ft_atoi(ft_valid_pid(av[1]));
		receive_signal(pid, av[2]);
	}
	write(1, "\n", 1);
	return (0);
}
