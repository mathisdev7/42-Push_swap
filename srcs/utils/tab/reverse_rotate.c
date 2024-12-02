/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:09:57 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/02 18:09:57 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	reverse_rotate(int *tab, int size)
{
	int	tmp;

	tmp = tab[size - 1];
	tab[size - 1] = tab[size - 2];
	tab[size - 2] = tmp;
}

void	rra(t_stack **stack, bool print)
{
	reverse_rotate(stack->tab, stack->size);
	if (print)
		printf("rra\n");
}

void	rrb(t_stack **stack, bool print)
{
	reverse_rotate(stack->tab, stack->size);
	if (print)
		printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	if (print)
		printf("rrr\n");
	rra(stack_a, print);
	rrb(stack_b, print);
}
