/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_algos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:54:44 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/27 12:58:50 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_nmin(t_stacks *stacks)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (i < stacks->len_a)
	{
		if (stacks->stack_a[i] < stacks->stack_a[i - 1])
			n = stacks->stack_a[i];
		i++;
	}
	while (stacks->stack_a[0] != n)
		r(stacks->stack_a, stacks->len_a, 'a');
	pb(stacks);
	return ;
}

void	sort_two(int *stack)
{
	if (stack[0] > stack[1])
		s(stack,  'a');
	return ;
}

void	sort_three(int *stack, int stack_len)
{
	while (1)	
	{
		if (stack[0] < stack[1] && stack[1] < stack[2])
			break;
		if ((stack[0] < stack[1] && stack[1] > stack[2]) ||
				(stack[0] > stack[1] && stack[1] > stack[2]))
			s(stack, 'a');
		if (stack[0] < stack[1] && stack[1] > stack[2])
			r(stack, stack_len, 'a');
		if (stack[0] > stack[1] && stack[1] < stack[2])
			rrx(stack, stack_len, 'a');
	}
	return ;
}

void	sort_four(t_stacks *stacks)
{
	push_nmin(stacks);
	sort_three(stacks->stack_a, stacks->len_a);
	pa(stacks);
	return ;
}

void	sort_five(t_stacks *stacks)
{
	push_nmin(stacks);
	sort_four(stacks);
	pa(stacks);
	return ;
}

/*void	debug(int *tab, int tab_size)
{
	int	i = 0;

	while (i < tab_size)
	{
		printf("tab[%i] = %i\n", i, tab[i]);
		i++;
	}
	return ;
}

int	main()
{
	t_stacks	*stacks;
	int	stack_len = 5;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (-1);
	stacks->stack_a = malloc(sizeof(int) * stack_len);
	if (!stacks->stack_a)
		return (-1);
	stacks->stack_b = malloc(sizeof(int) * stack_len);
	if (!stacks->stack_b)
		return (-1);
	stacks->len_a = stack_len;
	stacks->len_b = 0;
	stacks->stack_a[0] = 48;
	stacks->stack_a[1] = 32;
	stacks->stack_a[2] = 54;
	stacks->stack_a[3] = 27;
	stacks->stack_a[4] = 87;
	printf("pre : \n");
	debug(stacks->stack_a, stack_len);
	printf("post : \n");
	sort_five(stacks);
	debug(stacks->stack_a, stack_len);
	return (0);
}*/
