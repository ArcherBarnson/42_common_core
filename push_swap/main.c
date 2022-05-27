/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:08:14 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/27 17:02:34 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_display(t_stacks *stacks)
{
	int	i;
	

	i = -1;
	if (!stacks)
	{
		write(2, "No stacks are present, nice bro, good job\n", 42);
		return ;
	}
	while (++i < stacks->len_a)
		printf("A[%i] => %i\n", i, stacks->stack_a[i]);
	i = -1;
	write(1, "\n\n", 2);
	while (++i < stacks->len_b)
		printf("B[%i] => %i\n", i, stacks->stack_b[i]);
	return ;
}

void	err_msg(int err_code)
{
	if(err_code)
		write(2, "Error\n", 6);
	return ;
}

int	verify_stack(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!stacks)
		return (-1);
	while (i < stacks->len_a)
	{
		while (j < stacks->len_a)
		{
			if (stacks->stack_a[i] == stacks->stack_a[j])
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

void	pick_algo(t_stacks *stacks)
{
	if (stacks->len_a < 2)
		return ;
	if (stacks->len_a == 2)
		sort_two(stacks->stack_a);
	if (stacks->len_a == 3)
		sort_three(stacks->stack_a, stacks->len_a);
	if (stacks->len_a == 4)
		sort_four(stacks);
	if (stacks->len_a == 5)
		sort_five(stacks);
	return ;
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = NULL;
	stacks = ft_parsing(ac, av, stacks);
	if (!stacks || verify_stack(stacks) == -1)
	{
		err_msg(1);
		return (-1);
	}
	debug_display(stacks);
	if (stacks->len_a < 6)
		pick_algo(stacks);
	else
		radix(stacks);
	debug_display(stacks);
	return (0);
}
