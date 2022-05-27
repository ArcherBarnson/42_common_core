/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:35:01 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/23 10:50:06 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	print_arg(va_list args, char option)
{
	if (option == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	if (option == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (option == 'p')
		return (ft_putaddr_fd(va_arg(args, unsigned long long), 1, 0, 0));
	if (option == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1, 0));
	if (option == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1, 0));
	if (option == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1, 0));
	if (option == 'x' || option == 'X')
		return (ft_putnbr_hex_fd(va_arg(args, int), 1, 0, option));
	return (-1);
}

int	print_and_getsize(char const *s, va_list args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &(s[i]), 1);
			len++;
		}
		else if (s[i] == '%' && s[i + 1] == '%')
		{
			write(1, &(s[++i]), 1);
			len++;
		}
		else
			len += print_arg(args, s[++i]);
		i++;
	}
	return (len);
}

int	ft_printf(char const *s, ...)
{
	int		return_val;
	va_list	args;

	return_val = 0;
	va_start(args, s);
	return_val = print_and_getsize(s, args);
	va_end(args);
	return (return_val);
}
