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

static void push(t_stack **src, t_stack **dst)
{
	t_stack *temp;

	if (!*src)
		return;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
