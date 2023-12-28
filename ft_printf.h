/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:41:28 by ysemlali          #+#    #+#             */
/*   Updated: 2023/11/26 20:49:04 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	ft_parse(const char *input, va_list args);
int	handle_format_specifier(char specifier, va_list args);
int	ft_strlen(const char *str);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb, int i);
int	ft_puthex(unsigned int nb, int i);
int	ft_puthexup(unsigned int nb, int i);
int	ft_putptr(void *ptr, int i);
int	ft_putuns(unsigned long nb, int i);

#endif
