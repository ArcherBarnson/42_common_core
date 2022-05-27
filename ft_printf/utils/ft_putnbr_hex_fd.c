/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:37:55 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/09 15:29:39 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_fd(unsigned int n, int fd, int count, char x)
{
	char	c;
	char	*hextable;

	count = 0;
	if (x != 'x' && x != 'X')
		return (0);
	if (x == 'X')
		hextable = "0123456789ABCDEF";
	if (x == 'x')
		hextable = "0123456789abcdef";
	if (n >= 16)
		count = ft_putnbr_hex_fd(n / 16, fd, count + 1, x);
	c = hextable[n % 16];
	write(fd, &c, 1);
	count++;
	return (count);
}
