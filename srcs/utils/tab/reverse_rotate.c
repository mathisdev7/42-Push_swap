/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:09:57 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 22:40:05 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	temp = stack->tab[stack->size - 1];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[0] = temp;
}

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
