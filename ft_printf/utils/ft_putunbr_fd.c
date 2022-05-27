/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:05:14 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/09 18:23:30 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_fd(unsigned int n, int fd, int count)
{
	long	nb;
	char	c;

	count = 1;
	nb = (long)n;
	if (nb > 9)
		count += ft_putnbr_fd(nb / 10, fd, count + 1);
	c = nb % 10 + '0';
	write(fd, &c, 1);
	return (count);
}
