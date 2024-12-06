/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:39:58 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 22:42:22 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	value;
	int	target_value;

	get_best_push(stack_a, stack_b, &value, &target_value);
	rotate_to_top(value, target_value, stack_a, stack_b);
	pb(stack_a, stack_b);
}

int	get_min_cost(int rotations, int reverse_rotations)
{
	if (rotations <= reverse_rotations)
		return (rotations);
	else
		return (reverse_rotations);
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	value;
	int	target_value;

	i = 0;
	value = stack_b->tab[i];
	target_value = get_a_target(value, stack_a);
	while (stack_a->tab[i] != target_value)
		i++;
	if (i < stack_a->size / 2)
		while (stack_a->tab[0] != target_value)
			ra(stack_a);
	else
		while (stack_a->tab[0] != target_value)
			rra(stack_a);
	pa(stack_a, stack_b);
}
