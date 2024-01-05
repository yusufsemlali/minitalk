/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:41:21 by ysemlali          #+#    #+#             */
/*   Updated: 2023/11/26 20:49:23 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned long nb, int i)
{
	if (nb >= 10)
		i += ft_putuns(nb / 10, i);
	i += ft_putchar(nb % 10 + '0');
	return (i);
}
