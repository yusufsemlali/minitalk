/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:41:25 by ysemlali          #+#    #+#             */
/*   Updated: 2023/12/27 22:43:17 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *intput, ...)
{
	va_list	args;
	int		i;

	if (!intput)
		return (-1);
	i = 0;
	va_start(args, intput);
	while (*intput)
	{
		if (*intput == '%')
		{
			intput++;
			if (*intput == '\0')
				break ;
			i += handle_format_specifier(*intput, args);
		}
		else
			i += ft_putchar(*intput);
		intput++;
	}
	va_end(args);
	return (i);
}
