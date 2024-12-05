/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:52:20 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/05 22:52:20 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	find_position(t_stack *stack, int value)
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

int	calculate_cost(int pos, int stack_size)
{
	if (pos <= stack_size / 2)
		return (pos);
	return (stack_size - pos);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	find_max_position(t_stack *stack_b, int *max_value, int *max_pos)
{
	t_stack	*current;
	int		pos;

	current = stack_b;
	*max_value = current->value;
	*max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value > *max_value)
		{
			*max_value = current->value;
			*max_pos = pos;
		}
		current = current->next;
		pos++;
	}
}
