/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:41:28 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/06 16:44:25 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

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
int	ft_atoi(const char *str);

#endif
