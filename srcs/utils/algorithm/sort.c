/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:36:03 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/03 21:36:03 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int find_position(t_stack *stack, int value)
{
    int pos = 0;
    while (stack && stack->value != value)
    {
        pos++;
        stack = stack->next;
    }
    return (pos);
}

void ft_sort_three(t_stack **stack_a)
{
    int first = (*stack_a)->value;
    int second = (*stack_a)->next->value;
    int third = (*stack_a)->next->next->value;

    if (first > second && second < third && first < third)
        sa(stack_a);
    else if (first > second && second > third)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (first > second && second < third && first > third)
        ra(stack_a);
    else if (first < second && second > third && first < third)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (first < second && second > third && first > third)
        rra(stack_a);
}

bool is_in_chunk(int value, int *chunk, int chunk_size)
{
    int i = 0;
    while (i < chunk_size)
    {
        if (value == chunk[i])
            return (true);
        i++;
    }
    return (false);
}

int find_closest_in_chunk(t_stack *stack, int *chunk, int chunk_size, int stack_size)
{
    int min_cost = stack_size;
    int best_value = -1;
    int pos = 0;

    while (stack)
    {
        if (is_in_chunk(stack->value, chunk, chunk_size))
        {
            int cost = pos <= stack_size / 2 ? pos : stack_size - pos;
            if (cost < min_cost)
            {
                min_cost = cost;
                best_value = stack->value;
            }
        }
        pos++;
        stack = stack->next;
    }
    return (best_value);
}

static void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    int j = low;
    while (j < high)
    {
        if (arr[j] < pivot)
        {
            i++;
            ft_swap(&arr[i], &arr[j]);
        }
        j++;
    }
    ft_swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void ft_quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        ft_quick_sort(arr, low, pi - 1);
        ft_quick_sort(arr, pi + 1, high);
    }
}

void ft_sort_small(t_stack **stack_a)
{
    int size = ft_stack_size(*stack_a);

    if (size == 2)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            sa(stack_a);
    }
    else if (size == 3)
    {
        ft_sort_three(stack_a);
    }
}

void push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int *chunk, int chunk_size)
{
    int stack_size = ft_stack_size(*stack_a);
    int processed = 0;

    while (processed < chunk_size)
    {
        int closest = find_closest_in_chunk(*stack_a, chunk, chunk_size, stack_size);
        if (closest == -1) break;

        int pos = find_position(*stack_a, closest);
        int mid_point = stack_size / 2;

        if (pos <= mid_point)
            while (pos-- > 0) ra(stack_a);
        else
            while (pos++ < stack_size) rra(stack_a);

        pb(stack_a, stack_b);
        processed++;
        stack_size--;
    }
}

void push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        t_stack *current = *stack_b;
        int max_value = current->value;
        int max_pos = 0, pos = 0;

        while (current)
        {
            if (current->value > max_value)
            {
                max_value = current->value;
                max_pos = pos;
            }
            current = current->next;
            pos++;
        }

        int size_b = ft_stack_size(*stack_b);
        int mid_point = size_b / 2;

        if (max_pos <= mid_point)
            while (max_pos-- > 0) rb(stack_b);
        else
            while (max_pos++ < size_b) rrb(stack_b);

        pa(stack_a, stack_b);
    }
}

void ft_sort(t_stack **stack_a, t_stack **stack_b)
{
    int total = ft_stack_size(*stack_a);

    int chunk_count = total <= 50 ? 3 :
                      total <= 100 ? 4 :
                      total <= 200 ? 6 : 8;

    int chunk_size = (total + chunk_count - 1) / chunk_count;
    int sorted[total];

    t_stack *temp = *stack_a;
    int i = 0;
    while (temp)
    {
        sorted[i] = temp->value;
        temp = temp->next;
        i++;
    }
    ft_quick_sort(sorted, 0, total - 1);

    if (total <= 3)
    {
        ft_sort_small(stack_a);
        return;
    }

	i = 0;
    while (i < chunk_count)
    {
        int start = i * chunk_size;
        int current_size = (i == chunk_count - 1) ?
            (total - start) :
            (total - start > chunk_size ? chunk_size : total - start);

        int chunk[current_size];
        memcpy(chunk, sorted + start, current_size * sizeof(int));
        push_chunk_to_b(stack_a, stack_b, chunk, current_size);
        i++;
    }

    push_back_to_a(stack_a, stack_b);
}
