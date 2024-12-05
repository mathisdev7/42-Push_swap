/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:53:53 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/05 22:53:53 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	copy_stack_to_array(t_stack *stack, int *arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
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
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
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
