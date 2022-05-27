/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:41:36 by bgrulois          #+#    #+#             */
/*   Updated: 2022/05/27 17:05:18 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cpy_tab(int *tab, int tab_size)
{
	int	i;
	int	*dest;

	i = -1;
	dest = malloc(sizeof(int) * tab_size);
	if (!dest)
		return (0);
	while (++i < tab_size)
		dest[i] = tab[i];
	return (dest);
}

int	*bubble_sort(int *tab, int tab_size)
{
	int	i;
	int	j;
	int	tmp;
	int	*sorted_tab;

	i = -1;
	j = 0;
	tmp = 0;
	sorted_tab = cpy_tab(tab, tab_size);
	i = -1;
	while (++i < tab_size)
	{
		j = i;
		while (++j < tab_size)
		{
			if (sorted_tab[i] > sorted_tab[j])
			{
				tmp = sorted_tab[j];
				sorted_tab[j] = sorted_tab[i];
				sorted_tab[i] = tmp;
			}
		}
	}
	return (sorted_tab);
}

void	bruh(int *tab, int tab_size)
{
	int	i = 0;

	while (i < tab_size)
	{
		printf("tab[%i]:%i\n", i, tab[i]);
		i++;
	}
	return ;
}

int	*n_to_index(int *tab, int tab_size)
{
	int	*sorted_tab;
	int	i;
	int	j;

	i = 0;
	sorted_tab = bubble_sort(tab, tab_size);
	printf("size ==> %i\n", tab_size);
	while(i < tab_size)
	{
		j = 0;
		while(j < tab_size && i < tab_size)
		{
			if (tab[i] == sorted_tab[j])
			{
				tab[i] = j;
				i++;
			}
			j++;
		}
	}
	bruh(tab, tab_size);
	return (tab);
}

int	get_max_binary(int *tab, int tab_len) //ca ca sert a rien
{
	int	max;
	int	*sorted;
	
	max = 1;
	sorted = bubble_sort(tab, tab_len);
	printf("%i\n", sorted[tab_len - 1]);
	while (sorted[tab_len - 1] >= 2)
	{
		sorted[tab_len - 1] /= 2;
		max++;
	}
	free(sorted);
	printf("%i\n\n\n", max);
	return (max);
}

/*void	radix(t_stacks *stacks)
{
	int	i;
	int	j;
	int	static_len;
	int	*index_tab;

	i = 0;
	j = 0;
	static_len = stacks->len_a; //attention a ca
	index_tab = NULL;
	while (i < stacks->len_a) //ca c'est eclate
	{
		index_tab = n_to_index(stacks->stack_a, stacks->len_a);
		while (get_last_bit(index_tab[0]) == 0 && j < stacks->len_a)
		{
			r(stacks->stack_a, stacks->len_a, 'a');
			stacks->len_a--;
			j++;
			free(index_tab);
			index_tab = n_to_index(stacks->stack_a, stacks->len_a);
		}
		if (j + 1 >= stacks->len_a)
			byteshift_tab(index_tab, stacks->len_a);
		j = 0;
		pb(stacks);
		free(index_tab);
		i++;
	}
}*/

void	radix(t_stacks *stacks)
{
	int	i;
	int	j;
	int	len;
	int	max;
	
	j = 0;
	len = stacks->len_a; //lol jsp pk cest naze
	stacks->stack_a = n_to_index(stacks->stack_a, stacks->len_a);
	max = get_max_binary(stacks->stack_a, stacks->len_a);
	while (j < max) 
	{
		i = 0;
		while (i < len)
		{
			if ((stacks->stack_a[0] >> j) % 2 == 0)
				pb(stacks);
			else
				rrx(stacks->stack_a, stacks->len_a, 'a');
			i++;
		}
		while (stacks->len_b != 0)
			pa(stacks);
		j++;
	}
}
