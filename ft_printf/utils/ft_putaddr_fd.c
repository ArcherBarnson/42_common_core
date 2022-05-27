/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:38:53 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/22 19:27:41 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr_fd(unsigned long long n, int fd,
		unsigned long long count, int sw)
{
	char	c;
	char	*hextable;

	if (!n || n == 0)
	{
		write(fd, NULLRET, LEN);
		return (LEN);
	}
	count = 2;
	hextable = "0123456789abcdef";
	if (sw == 0)
	{
		write(fd, "0x", 2);
		sw = 1;
	}
	if (n >= 16)
		count = ft_putaddr_fd(n / 16, fd, count + 1, sw);
	c = hextable[n % 16];
	write(fd, &c, 1);
	count++;
	return (count);
}
