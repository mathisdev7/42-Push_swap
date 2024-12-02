/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:09:18 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/02 18:09:18 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rotate(int *tab, int size)
{
	int	tmp;

	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	ra(t_stack **stack, bool print)
{
	rotate(stack->tab, stack->size);
	if (print)
		printf("ra\n");
}

void	rb(t_stack **stack, bool print)
{
	rotate(stack->tab, stack->size);
	if (print)
		printf("rb\n");
}
