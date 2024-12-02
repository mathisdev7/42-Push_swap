/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:19:44 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/02 18:12:42 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*tab;
	int	size;
}		t_stack;

// core functions
void	ft_error(t_stack *stack);
void	ft_free(t_stack *stack);
bool	ft_is_duplicate(t_stack *stack, int value);
void	ft_print_array(t_stack *stack);

// stack operations
void	ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_stack_new(long nbr);
int		ft_stack_size(t_stack *stack);
bool	ft_is_sorted(t_stack *stack);

// sorting algorithms
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_three_sort(t_stack **stack);

// stack operations
void	push(int *tab_a, int *tab_b, int size);
void	sa(t_stack **stack, bool print);
void	sb(t_stack **stack, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	pa(t_stack **stack_a, t_stack **stack_b, bool print);
void	pb(t_stack **stack_a, t_stack **stack_b, bool print);
void	ra(t_stack **stack, bool print);
void	rb(t_stack **stack, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **stack, bool print);
void	rrb(t_stack **stack, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

#endif
