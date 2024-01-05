/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:41:38 by ysemlali          #+#    #+#             */
/*   Updated: 2023/11/26 18:11:54 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr, int count)
{
	unsigned long long	n;
	char				*base;
	int					i;

	i = 0;
	if (!ptr)
		return (i = ft_putstr("0x0"), i);
	else
	{
		base = "0123456789abcdef";
		n = (unsigned long long)ptr;
		if (count == 0)
			count += ft_putstr("0x");
		if (n >= 16)
			count = ft_putptr((void *)(n / 16), count);
		count++;
		ft_putchar(base[n % 16]);
	}
	return (count);
}
