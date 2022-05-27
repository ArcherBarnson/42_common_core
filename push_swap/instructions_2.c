/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:07:27 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/27 17:07:46 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
	write(1, "ss\n", 3);
	return ;
}

void	r(int *stack, int stack_len, char name)
{
	int	temp;

	temp = stack[0];
	offset_stack_down(stack, stack_len);
	stack[stack_len - 1] = temp;
	write(1, "r", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
	return ;
}

void	rrx(int *stack, int stack_len, char x)
{
	int	temp;

	temp = stack[0];
	offset_stack_up(stack, stack_len);
	stack[stack_len - 1] = temp;
	write(1, "rr", 2);
	write(1, &x, 1);
	write(1, "\n", 1);
	return ;
}

void	rr(t_stacks *stacks)
{
	int	temp;

	temp = stacks->stack_a[0];
	offset_stack_up(stacks->stack_a, stacks->len_a);
	stacks->stack_a[stacks->len_a - 1] = temp;
	temp = stacks->stack_b[0];
	offset_stack_up(stacks->stack_b, stacks->len_b);
	stacks->stack_b[stacks->len_b - 1] = temp;
	write(1, "rr\n", 3);
	printf("%i\n%i", stacks->len_a, stacks->len_b);
	return ;
}

void	rrr(t_stacks *stacks)
{
	int	temp;

	temp = stacks->stack_a[stacks->len_a - 1];
	offset_stack_down(stacks->stack_a, stacks->len_a);
	stacks->stack_a[0] = temp;
	temp = stacks->stack_b[stacks->len_b - 1];
	offset_stack_down(stacks->stack_b, stacks->len_b);
	stacks->stack_b[0] = temp;
	write(1, "rrr\n", 4);
	return ;
}
