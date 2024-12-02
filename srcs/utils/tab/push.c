/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:00:43 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/02 18:00:43 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	push(t_stack *tab_a, t_stack *tab_b, int size)
{
	int	i;

	i = tab_b->size;
	while (i > 0)
	{
		tab_b->tab[i] = tab_b->tab[i - 1];
		i--;
	}
	tab_b->tab[0] = tab_a->tab[0];
	i = 0;
	while (i < tab_a->size - 1)
	{
		tab_a->tab[i] = tab_a->tab[i + 1];
		i++;
	}
	tab_a->size--;
	tab_b->size++;
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool print)
{
	push(stack_b->tab, stack_a->tab, stack_b->size);
	if (print)
		printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, bool print)
{
	push(stack_a->tab, stack_b->tab, stack_a->size);
	if (print)
		printf("pb\n");
}
