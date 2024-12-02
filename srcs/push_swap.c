/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:07:11 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/02 18:07:11 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	i;

	if (argc < 2)
		ft_error(NULL);
	argv = ft_split(argv[1], ' ');
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (argv[i])
	{
		long num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(stack_a);
		if (ft_is_duplicate(stack_a, num))
			ft_error(stack_a);
		ft_stack_add_back(&stack_a, ft_stack_new(num));
		i++;
	}
	if (!ft_is_sorted(stack_a))
	{
		if (ft_stack_size(stack_a) == 3)
			ft_three_sort(&stack_a);
		else if (ft_stack_size(stack_a) == 2 && stack_a->tab[0] > stack_a->tab[1])
			sa(&stack_a, true);
		else
			ft_sort(&stack_a, &stack_b);
	}
	ft_print_stack(stack_a);
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}
