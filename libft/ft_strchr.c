/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:59:14 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/09 17:14:44 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	int	i;

	i = 0;
	c %= 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == c)
		return ((char *)(&s[i]));
	return (0);
}
