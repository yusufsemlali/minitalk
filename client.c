/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:00:48 by ysemlali          #+#    #+#             */
/*   Updated: 2023/12/28 12:09:31 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

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
		binary[7 - i] = ((ascii & (1 << i)) ? '1' : '0');
		i--;
	}
	binary[8] = '\0';
	return (binary);
}

int	main(int ac, char **av)
{
    char	*binary;
    int		signal;
    pid_t	pid;
    int		i;
    int		j;

    if (ac == 3)
    {
        pid = ft_atoi(av[1]);
        printf("%d", pid);
        j = 0;
        while (av[2][j] != '\0')
        {
            binary = ascii_to_binary((int)av[2][j]);
            i = 0;
            while (binary[i] != '\0')
            {
                if (binary[i] == '1')
                    signal = SIGUSR1;
                else
                    signal = SIGUSR2;
                if (kill(pid, signal) == -1)
                {
                    write(1, "Error sending signal", 20);
                    free(binary);
                    return (1);
                }
                usleep(210);
                i++;
            }
            free(binary);
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
