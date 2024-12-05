/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:52:43 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/05 22:49:50 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	long	num;

	if (argc < 2)
		ft_error(NULL);
	argv = ft_split(argv[1], ' ');
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(stack_a);
		if (ft_is_duplicate(stack_a, num))
			ft_error(stack_a);
		ft_stack_add_back(&stack_a, ft_stack_new(num));
		i++;
	}
	if (!ft_is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b);
	ft_free(stack_a);
	return (0);
}
