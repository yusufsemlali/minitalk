/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:43:47 by ysemlali          #+#    #+#             */
/*   Updated: 2023/12/28 11:35:30 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

char	g_binary[9];
int		g_i = 0;

char	binary_to_ascii(char *binary)
{
	char	c;
	int		i;

	c = 0;
	i = 0;
	while (i < 8)
	{
		c <<= 1;
		if (binary[i] == '1')
			c |= 1;
		i++;
	}
	return (c);
}
void	handle_signal(int sig)
{
    char	c;
    if (sig == SIGUSR1)
        g_binary[g_i++] = '1'; 
    else
        g_binary[g_i++] = '0';
    if (g_i == 8)
    {
        g_binary[g_i] = '\0';
        c = binary_to_ascii(g_binary);
        write(1, &c, 1);
        g_i = 0;
    }
}

int	main(void)
{
	struct sigaction	sa;
	int					sig1;
	int					sig2;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sig1 = sigaction(SIGUSR1, &sa, NULL);
	if (sig1 == -1)
	{
		ft_printf("Error setting up SIGUSR1 handler");
		exit(1);
	}
	sig2 = sigaction(SIGUSR2, &sa, NULL);
	if (sig2 == -1)
	{
		ft_printf("Error setting up SIGUSR2 handler");
		exit(1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
