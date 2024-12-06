/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:59:44 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 14:07:15 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *stack)
{
	ft_free(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_free(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->tab)
		free(stack->tab);
	free(stack);
}

bool	ft_is_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->tab[i] == stack->tab[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
