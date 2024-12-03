/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:59:44 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/02 17:59:44 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_error(t_stack *stack)
{
	ft_free(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_free(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

bool	ft_is_duplicate(t_stack *stack, int value)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->value == value)
			return (true);
		current = current->next;
	}
	return (false);
}

void	ft_print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_putnbr_fd(current->value, 1);
		ft_putchar_fd('\n', 1);
		current = current->next;
	}
}
