/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:51:00 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/05 22:51:00 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	is_in_chunk(int value, int *chunk, int chunk_size)
{
	int	i;

	i = 0;
	while (i < chunk_size)
	{
		if (value == chunk[i])
			return (true);
		i++;
	}
	return (false);
}

int	find_closest_in_chunk(t_stack *stack, int *chunk, int chunk_size,
		int stack_size)
{
	int	min_cost;
	int	best_value;
	int	pos;
	int	cost;

	min_cost = stack_size;
	best_value = -1;
	pos = 0;
	while (stack)
	{
		if (is_in_chunk(stack->value, chunk, chunk_size))
		{
			cost = calculate_cost(pos, stack_size);
			if (cost < min_cost)
			{
				min_cost = cost;
				best_value = stack->value;
			}
		}
		pos++;
		stack = stack->next;
	}
	return (best_value);
}

void	push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int *chunk,
		int chunk_size)
{
	int	stack_size;
	int	processed;
	int	closest;
	int	pos;

	stack_size = ft_stack_size(*stack_a);
	processed = 0;
	while (processed < chunk_size)
	{
		closest = find_closest_in_chunk(*stack_a, chunk, chunk_size,
				stack_size);
		if (closest == -1)
			break ;
		pos = find_position(*stack_a, closest);
		if (pos <= stack_size / 2)
			while (pos-- > 0)
				ra(stack_a);
		else
			while (pos++ < stack_size)
				rra(stack_a);
		pb(stack_a, stack_b);
		processed++;
		stack_size--;
	}
}

void	process_chunks(t_stack **stack_a, t_stack **stack_b, t_chunk_data *data)
{
	int	chunk_size;
	int	i;
	int	start;
	int	current_size;
	int	*chunk;

	chunk_size = (data->total + data->chunk_count - 1) / data->chunk_count;
	i = 0;
	while (i < data->chunk_count)
	{
		start = i * chunk_size;
		if (i == data->chunk_count - 1)
			current_size = data->total - start;
		else if (data->total - start > chunk_size)
			current_size = chunk_size;
		else
			current_size = data->total - start;
		chunk = malloc(current_size * sizeof(int));
		if (!chunk)
			return ;
		ft_memcpy(chunk, data->sorted + start, current_size * sizeof(int));
		push_chunk_to_b(stack_a, stack_b, chunk, current_size);
		free(chunk);
		i++;
	}
}

int	get_chunk_count(int total)
{
	if (total <= 50)
		return (3);
	if (total <= 100)
		return (4);
	if (total <= 200)
		return (6);
	return (8);
}
