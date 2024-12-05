/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:19:44 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/05 22:59:49 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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

typedef struct s_chunk_data
{
	int				*sorted;
	int				total;
	int				chunk_count;
}					t_chunk_data;

// core functions
void				ft_error(t_stack *stack);
void				ft_free(t_stack *stack);
bool				ft_is_duplicate(t_stack *stack, int value);
bool				ft_is_sorted(t_stack *stack);
t_stack				*ft_stack_new(long nbr);
void				ft_stack_add_back(t_stack **stack, t_stack *new);
int					ft_stack_size(t_stack *stack);
t_stack				*ft_find_min(t_stack *stack);
t_stack				*ft_find_max(t_stack *stack);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				copy_stack_to_array(t_stack *stack, int *array);

// sorting functions
void				ft_sort(t_stack **stack_a, t_stack **stack_b);
void				push_chunk_to_b(t_stack **stack_a, t_stack **stack_b,
						int *chunk, int chunk_size);
void				push_back_to_a(t_stack **stack_a, t_stack **stack_b);

// stack operations
void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **a, t_stack **b);

int					find_position(t_stack *stack, int value);
int					calculate_cost(int pos, int stack_size);
void				ft_swap(int *a, int *b);
int					partition(int arr[], int low, int high);
void				find_max_position(t_stack *stack_b, int *max_value,
						int *max_pos);
// chunk functions
int					get_chunk_count(int total);
void				process_chunks(t_stack **stack_a, t_stack **stack_b,
						t_chunk_data *data);
#endif
