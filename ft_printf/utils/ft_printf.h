/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:12:07 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/23 10:50:10 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __linux__
#  define LEN 5
#  define NULLRET "(nil)"
# endif

# ifdef __APPLE__
#  define LEN 3
#  define NULLRET "0x0"
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar_fd(int c, int fd);
int		ft_putnbr_fd(int n, int fd, int count);
int		ft_putnbr_hex_fd(unsigned int n, int fd, int count, char x);
int		ft_putstr_fd(char *s, int fd);
int		ft_putaddr_fd(unsigned long long n, int fd,
			unsigned long long count, int sw);
int		ft_putunbr_fd(unsigned int n, int fd, int count);
int		ft_printf(char const *s, ...);
size_t	ft_strlen(char *str);
#endif
