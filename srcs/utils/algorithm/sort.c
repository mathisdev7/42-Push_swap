/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:36:03 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/05 22:53:21 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

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

void	ft_quick_sort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		ft_quick_sort(arr, low, pi - 1);
		ft_quick_sort(arr, pi + 1, high);
	}
}

void	ft_sort_small(t_stack **stack_a)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (size == 3)
		ft_sort_three(stack_a);
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size_b;
	int	max_value;
	int	max_pos;

	while (*stack_b)
	{
		find_max_position(*stack_b, &max_value, &max_pos);
		size_b = ft_stack_size(*stack_b);
		if (max_pos <= size_b / 2)
			while (max_pos-- > 0)
				rb(stack_b);
		else
			while (max_pos++ < size_b)
				rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int				total;
	int				*sorted;
	t_chunk_data	data;

	total = ft_stack_size(*stack_a);
	if (total <= 3)
	{
		ft_sort_small(stack_a);
		return ;
	}
	sorted = malloc(total * sizeof(int));
	if (!sorted)
		return ;
	copy_stack_to_array(*stack_a, sorted);
	ft_quick_sort(sorted, 0, total - 1);
	data.sorted = sorted;
	data.total = total;
	data.chunk_count = get_chunk_count(total);
	process_chunks(stack_a, stack_b, &data);
	push_back_to_a(stack_a, stack_b);
	free(sorted);
}
