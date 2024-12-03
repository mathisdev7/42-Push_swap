/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:36:03 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/03 21:36:03 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static int	find_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack && stack->value != value)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	ft_first_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_node;
	int		size;
	int		pos;

	while (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
	{
		min_node = ft_find_min(*stack_a);
		size = ft_stack_size(*stack_a);
		pos = find_position(*stack_a, min_node->value);

		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(stack_a);
		}
		else
		{
			while (pos++ < size)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	ft_sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;

	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}


