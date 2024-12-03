/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:00:22 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/02 18:00:22 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

bool	ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return true;
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return false;
		stack = stack->next;
	}
	return true;
}

t_stack *ft_find_min(t_stack *stack)
{
	t_stack *min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack *ft_find_max(t_stack *stack)
{
	t_stack *max;

	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack *ft_find_second_min(t_stack *stack)
{
	t_stack *min;
	t_stack *second_min;

	min = ft_find_min(stack);
	second_min = ft_find_min(stack);
	while (stack)
	{
		if (stack->value > min->value && stack->value < second_min->value)
			second_min = stack;
		stack = stack->next;
	}
	return (second_min);
}

t_stack	*ft_stack_new(long nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = nbr;
	new->next = NULL;
	return (new);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (!new)
		return;
	if (!*stack)
	{
		*stack = new;
		return;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new;
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
