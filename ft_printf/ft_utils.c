/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:09:04 by ysemlali          #+#    #+#             */
/*   Updated: 2023/11/26 17:12:14 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int), 0));
	else if (specifier == 'x')
		return (ft_puthex(va_arg(args, int), 0));
	else if (specifier == 'X')
		return (ft_puthexup(va_arg(args, int), 0));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *), 0));
	else if (specifier == 'u')
		return (ft_putuns(va_arg(args, unsigned int), 0));
	else if (specifier == '%')
		return (ft_putchar('%'));
	else
	{
		ft_printf("%c im here\n", specifier);
		return (ft_putchar(specifier));
	}
}
