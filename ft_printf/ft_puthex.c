/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:41:34 by ysemlali          #+#    #+#             */
/*   Updated: 2023/11/26 20:49:10 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nb, int i)
{
	if (nb >= 16)
		i = ft_puthex(nb / 16, i);
	if (nb % 16 < 10)
		i += ft_putchar(nb % 16 + '0');
	else
		i += ft_putchar(nb % 16 - 10 + 'a');
	return (i);
}
