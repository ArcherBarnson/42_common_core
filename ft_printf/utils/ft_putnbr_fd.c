/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:19:38 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/23 10:50:24 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd, int count)
{
	long	nb;
	char	c;

	count = 1;
	nb = (long)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		count++;
		nb = -nb;
		if (nb == 2147483648)
		{
			write (fd, "2147483648", 10);
			return (11);
		}
	}
	if (nb > 9)
		count += ft_putnbr_fd(nb / 10, fd, count + 1);
	c = nb % 10 + '0';
	write(fd, &c, 1);
	return (count);
}
