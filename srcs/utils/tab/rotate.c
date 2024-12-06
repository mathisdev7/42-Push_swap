/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:09:18 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 22:39:36 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size <= 1)
		return ;
	temp = stack->tab[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[stack->size - 1] = temp;
}

void	ra(t_stack *stack)
{
	rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack)
{
	rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
