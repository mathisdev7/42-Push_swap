/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:19:44 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 22:54:24 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long	*tab;
	int		size;
	int		volume;
}			t_stack;

// core functions
void		ft_error(t_stack *stack);
void		ft_free(t_stack *stack);
bool		ft_is_duplicate(t_stack *stack);
bool		ft_is_sorted(long *tab, int size);
int			ft_check_args(int argc, char **argv, t_stack *stack_a);
t_stack		*ft_init_stack(int volume, char **argv);

// sorting functions
void		ft_sort(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_simple(t_stack *stack_a);
void		ft_sort_three(t_stack *stack_a);
void		push_to_b(t_stack *stack_a, t_stack *stack_b);
void		push_to_a(t_stack *stack_a, t_stack *stack_b);
void		min_to_top(t_stack *stack_a);
void		get_best_push(t_stack *stack_a, t_stack *stack_b, int *value,
				int *target_value);
int			get_a_target(long value, t_stack *stack_a);
int			get_push_cost(long value, int target_value, t_stack *stack_a,
				t_stack *stack_b);
int			get_b_target(long value, t_stack *stack_b);
void		rotate_to_top(long value, int target_value, t_stack *stack_a,
				t_stack *stack_b);

// utils functions
int			get_min_cost(int rotations, int reverse_rotations);

// stack operations
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *a, t_stack *b);

#endif
