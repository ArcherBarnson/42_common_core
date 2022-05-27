/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:46:16 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/27 16:58:09 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char	*str)
{
	int	i;
	int	sign;
	long long	tot;

	i = 0;
	sign = 1;
	tot = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && tot < 2147483648)
	{
		tot = tot * 10 + (str[i] - '0');
		i++;
	}
	return (tot * sign);
}
