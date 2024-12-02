/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:08:49 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/02 18:08:49 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	swap(int *tab, int size)
{
	int	tmp;

	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	sa(t_stack **stack, bool print)
{
	swap(stack->tab, stack->size);
	if (print)
		printf("sa\n");
}

void	sb(t_stack **stack, bool print)
{
	swap(stack->tab, stack->size);
	if (print)
		printf("sb\n");
}

