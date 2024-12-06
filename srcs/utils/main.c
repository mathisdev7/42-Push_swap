/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:46:16 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/06 22:47:27 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_words(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

t_stack	*ft_init_stack(int volume, char **argv)
{
	t_stack	*stack;
	int		tab_size;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (volume == 1)
	{
		tab_size = ft_count_words(argv[1], ' ');
		if (tab_size == 0)
			return (free(stack), NULL);
		stack->tab = malloc(sizeof(long) * tab_size);
	}
	else
		stack->tab = malloc(sizeof(long) * volume);
	if (!stack->tab)
		return (free(stack), NULL);
	stack->size = 0;
	stack->volume = volume;
	return (stack);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_check_str_args(char *str, t_stack *stack_a)
{
	int		i;
	int		words;
	char	**tab;
	long	num;

	i = 0;
	tab = ft_split(str, ' ');
	if (!tab)
		return (0);
	words = ft_count_words(str, ' ');
	while (tab[i] && i < words)
	{
		num = ft_atoi(tab[i]);
		if (num == 2147483648)
		{
			ft_free_tab(tab);
			ft_free(stack_a);
			return (0);
		}
		stack_a->tab[i] = num;
		stack_a->size++;
		i++;
	}
	ft_free_tab(tab);
	return (ft_is_duplicate(stack_a));
}

int	ft_check_args(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	long	num;

	i = 1;
	if (argc == 2)
		return (ft_check_str_args(argv[1], stack_a));
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num == -2 || (num == 0 && argv[i][0] != '0'))
			return (0);
		if (stack_a->size >= stack_a->volume)
			return (0);
		stack_a->tab[stack_a->size++] = num;
		i++;
	}
	if (!ft_is_duplicate(stack_a))
		return (0);
	return (1);
}
