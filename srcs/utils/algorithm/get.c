/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:57:27 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 22:41:24 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rotations(t_stack *stack, long value)
{
	int	i;

	i = 0;
	while (stack->tab[i] != value)
		i++;
	return (i);
}

int	get_push_cost(long value, int target_value, t_stack *stack_a,
		t_stack *stack_b)
{
	int	rotations_a;
	int	rev_rotations_a;
	int	rotations_b;
	int	rev_rotations_b;

	rotations_a = get_rotations(stack_a, value);
	rev_rotations_a = stack_a->size - rotations_a;
	rotations_b = get_rotations(stack_b, target_value);
	rev_rotations_b = stack_b->size - rotations_b;
	return (get_min_cost(rotations_a, rev_rotations_a)
		+ get_min_cost(rotations_b, rev_rotations_b));
}

int	get_b_target(long value, t_stack *stack_b)
{
	int	closest_smaller;
	int	max_value;
	int	current;
	int	i;

	if (!stack_b || stack_b->size <= 0)
		return (0);
	closest_smaller = INT_MIN;
	max_value = INT_MIN;
	i = 0;
	current = stack_b->tab[0];
	while (i < stack_b->size)
	{
		current = stack_b->tab[i];
		if (current > max_value)
			max_value = current;
		if (current < value && current > closest_smaller)
			closest_smaller = current;
		i++;
	}
	if (closest_smaller == INT_MIN)
		return (max_value);
	return (closest_smaller);
}

void	get_best_push(t_stack *stack_a, t_stack *stack_b, int *best_value,
		int *best_target_value)
{
	int	i;
	int	push_cost;
	int	lower_push_cost;

	i = 0;
	*best_value = stack_a->tab[i];
	*best_target_value = get_b_target(*best_value, stack_b);
	push_cost = get_push_cost(*best_value, *best_target_value, stack_a,
			stack_b);
	lower_push_cost = push_cost;
	while (i < stack_a->size)
	{
		push_cost = get_push_cost(stack_a->tab[i],
				get_b_target(stack_a->tab[i], stack_b), stack_a, stack_b);
		if (push_cost < lower_push_cost)
		{
			lower_push_cost = push_cost;
			*best_value = stack_a->tab[i];
			*best_target_value = get_b_target(*best_value, stack_b);
		}
		i++;
	}
}

int	get_a_target(long value, t_stack *stack_a)
{
	int	closest_greater;
	int	min_value;
	int	current;
	int	i;

	if (!stack_a || stack_a->size <= 0)
		return (0);
	closest_greater = INT_MAX;
	min_value = INT_MAX;
	i = 0;
	while (i < stack_a->size)
	{
		current = stack_a->tab[i];
		if (current < min_value)
			min_value = current;
		if (current > value && current < closest_greater)
			closest_greater = current;
		i++;
	}
	if (closest_greater == INT_MAX)
		return (min_value);
	return (closest_greater);
}
