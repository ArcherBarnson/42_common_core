/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:08:06 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/27 17:04:24 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_str(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str && str[i])
	{
		if (str[i] == '-' && (str[i + 1] < '0' || str[i + 1] > '9'))
			return (-1);
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			if (str[i] == '-')
				i++;
			n++;
			while (str[i] && (str[i] >= '0' && str[i] <= '9'))
				i++;
		}
		else if (str[i] != ' ')
			return (-1);
		else
			i++;
	}
	return (n);
}

int	assign_int(int *stack, int stack_pos, char n[11], int j)
{
	long long	nb;
	n[j] = '\0';
	nb = ft_atoll(n);
	if (nb > 2147483647 || nb < -2147483648)
		return (-1);
	stack[stack_pos] = ft_atoi(n);
	ft_bzero(n);
	stack_pos++;
	return (stack_pos);
}
int	get_ints(char *str, int *stack, int stack_pos)
{
	int	i;
	int	j;
	char	n[11];

	i = -1;
	j = 0;
	while (str && str[++i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-'))
		{
			if (str[i] == '-' && j == 0)
				n[j++] = str[i++];
			while (str[i] >= '0' && str[i] <= '9')
				n[j++] = str[i++];
			stack_pos = assign_int(stack, stack_pos, n, j);
			if (stack_pos == -1)
				return (-1);
			j = 0;
		}
		if (str[i] == '\0')
			return (stack_pos);
	}
	return (stack_pos);
}

t_stacks	*fill_stack(char **av, t_stacks *stacks)
{
	int	i;
	int	stack_pos;

	stacks->len_b = 0; //stacks->len_a;
	stacks->stack_b = malloc(sizeof(int) * stacks->len_a);
	if (!stacks->stack_b)
		return (NULL);
	i = 1;
	stack_pos = 0;
	while (av && av[i])
	{
		stack_pos = get_ints(av[i], stacks->stack_a, stack_pos);
		if (stack_pos == -1)
			return (NULL);
		i++;
	}
	return (stacks);
}

t_stacks	*ft_parsing(int ac, char **av, t_stacks *stacks)
{
	int	i;
	int	malloc_size;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	i = 1;
	malloc_size = 0;
	stacks->stack_a = NULL;
	if (ac < 2)
		return (NULL);
	while (av[i])
	{
		if(verify_str(av[i]) < 0)
			return (NULL);
		malloc_size += verify_str(av[i]);
		i++;
	}
	stacks->stack_a = malloc(sizeof(int) * (malloc_size));
	if (!stacks->stack_a)
		return (NULL);
	stacks->len_a = malloc_size;
	return (fill_stack(av, stacks));
}
