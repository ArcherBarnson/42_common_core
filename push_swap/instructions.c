/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:04:10 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/27 17:08:21 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	offset_stack_down(int *tab, int tab_len)
{
	int	i;
	
	i = 0;
	while (i < tab_len)
	{
		tab[tab_len] = tab[tab_len - 1];
		tab_len--;
	}
	return ;
}

void	offset_stack_up(int *tab, int tab_len)
{
	int	i;

	i = 0;
	while (i < tab_len)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	return ;
}

void	pb(t_stacks *stacks)
{
	if (stacks->len_a <= 0)
	{
		write(2, "Cannot proceed : stack A is empty\n", 35);
		return ;
	}
	offset_stack_down(stacks->stack_b, stacks->len_b);
	stacks->stack_b[0] = stacks->stack_a[0];
	offset_stack_up(stacks->stack_a, stacks->len_a);
	stacks->len_b++;
	stacks->len_a--;
	write(1, "pb\n", 3);
	return ;
}

void	pa(t_stacks *stacks)
{
	if (stacks->len_b <= 0)
	{
		write(2, "Cannot proceed : stack B is empty\n", 35);
		return ;
	}
	offset_stack_down(stacks->stack_a, stacks->len_a);
	stacks->stack_a[0] = stacks->stack_b[0];
	offset_stack_up(stacks->stack_b, stacks->len_b);
	stacks->len_a++;
	stacks->len_b--;
	write(1, "pa\n", 3);
	return ;
}

void	s(int *stack, char name)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	write(1, "s", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
	return ;
}

/*
int	main()
{
	
	t_stacks	*stacks;
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (-1);
	stacks->stack_a = malloc(sizeof(int) * 7);
	stacks->stack_a[0] = 1;
	stacks->stack_a[1] = 2;
	stacks->stack_a[2] = 3;
	stacks->stack_a[3] = 4;
	stacks->len_a = 4, stacks->len_b = 2;
	int	i  = -1;
	stacks->stack_b = malloc(sizeof(int) * 7);
	stacks->stack_b[0] = 5;
	stacks->stack_b[1] = 6;
	while (++i < 6)
		printf("a[%i] = %i\n", i, stacks->stack_a[i]);
	i = -1;
	//offset_stack_down(a, last_a);
	while (++i < 6)
		printf("b[%i] = %i\n", i, stacks->stack_b[i]);
	write(1, "\n\n", 2);
	//rrx(stacks->stack_a, stacks->len_a, 'a');
	rrr(stacks);
	write(1, "\n\n", 2);
	i = -1;
	while (++i < 6)
		printf("a[%i] = %i\n", i, stacks->stack_a[i]);
	i = -1;
	while (++i < 6)
		printf("b[%i] = %i\n", i, stacks->stack_b[i]);
	return (0);
}*/
