/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:36:03 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 22:42:49 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *stack_a)
{
	int	tab_0;
	int	tab_1;
	int	tab_2;

	if (stack_a->size != 3)
		return ;
	tab_0 = stack_a->tab[0];
	tab_1 = stack_a->tab[1];
	tab_2 = stack_a->tab[2];
	if (tab_0 > tab_1 && tab_1 < tab_2 && tab_0 < tab_2)
		sa(stack_a);
	else if (tab_0 > tab_1 && tab_1 > tab_2)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (tab_0 > tab_1 && tab_1 < tab_2 && tab_0 > tab_2)
		ra(stack_a);
	else if (tab_0 < tab_1 && tab_1 > tab_2 && tab_0 < tab_2)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (tab_0 < tab_1 && tab_1 > tab_2 && tab_0 > tab_2)
		rra(stack_a);
}

void	ft_sort_simple(t_stack *stack_a)
{
	if (stack_a->size == 2)
	{
		if (stack_a->tab[0] > stack_a->tab[1])
			ra(stack_a);
	}
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
}

void	rotate_to_top(long value, int target_value, t_stack *stack_a,
		t_stack *stack_b)
{
	int	index_a;
	int	index_b;

	index_a = 0;
	index_b = 0;
	while (stack_a->tab[index_a] != value)
		index_a++;
	while (stack_b->tab[index_b] != target_value)
		index_b++;
	if (index_a < stack_a->size / 2)
		while (stack_a->tab[0] != value)
			ra(stack_a);
	else
		while (stack_a->tab[0] != value)
			rra(stack_a);
	if (index_b < stack_b->size / 2)
		while (stack_b->tab[0] != target_value)
			rb(stack_b);
	else
		while (stack_b->tab[0] != target_value)
			rrb(stack_b);
}

void	min_to_top(t_stack *stack_a)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min_index = 0;
	min = stack_a->tab[0];
	while (i < stack_a->size)
	{
		if (min > stack_a->tab[i])
		{
			min = stack_a->tab[i];
			min_index = i;
		}
		i++;
	}
	if (min_index < stack_a->size / 2)
		while (stack_a->tab[0] != min)
			ra(stack_a);
	else
		while (stack_a->tab[0] != min)
			rra(stack_a);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a->tab, stack_a->size))
		return ;
	if (stack_a->size <= 3)
	{
		ft_sort_simple(stack_a);
		return ;
	}
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		push_to_b(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	while (stack_b->size > 0)
	{
		push_to_a(stack_a, stack_b);
	}
	min_to_top(stack_a);
}
