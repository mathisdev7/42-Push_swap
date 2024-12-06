/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:52:43 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 23:07:34 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static bool	ft_is_zero_to_nine(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	ft_check_number(const char *str, int *i)
{
	int		start;
	long	num;
	char	*number_part;

	start = *i;
	while (ft_is_zero_to_nine(str[*i]))
		(*i)++;
	number_part = ft_substr(str, start, *i - start);
	if (!number_part)
		return (false);
	num = ft_atoi(number_part);
	free(number_part);
	return (num >= -2147483648 && num <= 2147483647);
}

bool	ft_is_valid_number_string(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			i++;
			if (!ft_is_zero_to_nine(str[i]))
				return (false);
		}
		if (!ft_is_zero_to_nine(str[i]))
			return (false);
		if (!ft_check_number(str, &i))
			return (false);
		if (str[i] == ' ')
			i++;
		else if (str[i] != '\0')
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	while (argv[1] && !ft_is_valid_number_string(argv[1]))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	stack_a = ft_init_stack(argc - 1, argv);
	stack_b = ft_init_stack(argc - 1, argv);
	if (!stack_b || !stack_a || !ft_check_args(argc, argv, stack_a))
	{
		ft_free(stack_a);
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	ft_sort(stack_a, stack_b);
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}
