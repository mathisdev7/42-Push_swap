/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:55:06 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/02 17:55:06 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_error(t_stack *stack)
{
	ft_free(stack);
	write(2, "Error\n", 5);
	exit(1);
}

void	ft_free(t_stack *stack)
{
	if (stack->tab)
		free(stack->tab);
	if (stack)
		free(stack);
}

bool	ft_is_duplicate(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->tab[i] == value)
			return (true);
		i++;
	}
	return (false);
}

void	ft_print_array(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		printf("%d\n", stack->tab[i]);
		i++;
	}
}
