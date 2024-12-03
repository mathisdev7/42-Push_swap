/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:19:44 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/03 18:27:17 by mazeghou         ###   ########.fr       */
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
	int				value;
	struct s_stack	*next;
}					t_stack;

// core functions
void	ft_error(t_stack *stack);
void	ft_free(t_stack *stack);
bool	ft_is_duplicate(t_stack *stack, int value);
void	ft_print_stack(t_stack *stack);

// stack operations
void	ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_stack_new(long nbr);
int		ft_stack_size(t_stack *stack);
bool	ft_is_sorted(t_stack *stack);
t_stack	*ft_find_min(t_stack *stack);
t_stack	*ft_find_max(t_stack *stack);
t_stack	*ft_find_second_min(t_stack *stack);

// sorting algorithms
void	ft_first_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack);

// stack operations
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);

#endif
