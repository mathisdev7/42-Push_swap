/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:08:49 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 21:42:41 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size <= 1)
		return ;
	temp = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = temp;
}

void	sa(t_stack *stack)
{
	swap(stack);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack)
{
	swap(stack);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
