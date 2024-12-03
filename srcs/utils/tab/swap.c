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

static void swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    if (!*stack || !(*stack)->next)
        return;
    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void sa(t_stack **stack)
{
    swap(stack);
    ft_putstr_fd("sa\n", 1);
}

void sb(t_stack **stack)
{
    swap(stack);
    ft_putstr_fd("sb\n", 1);
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_putstr_fd("ss\n", 1);
}

