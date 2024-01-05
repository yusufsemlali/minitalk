/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:41:36 by ysemlali          #+#    #+#             */
/*   Updated: 2023/11/26 20:48:57 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int i)
{
	long	n;

	n = (long)nb;
	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		i++;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10, i);
	}
	ft_putchar(n % 10 + '0');
	i++;
	return (i);
}
