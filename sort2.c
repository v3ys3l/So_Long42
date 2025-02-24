/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:04:14 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/24 13:01:30 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		sa(s, 0);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, 0);
		rra(s, 0);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s, 0);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, 0);
		ra(s, 0);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra(s, 0);
}

int	find_min_index(int *arr, int size)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = arr[0];
	index = 0;
	while (i < size)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	r_or_rr(t_stack *stack, int min_value, int min_index)
{
	if (min_index >= stack->size_a / 2 + stack->size_a % 2)
		while (stack->a[0] != min_value && ft_checked_sorted(stack->a,
				stack->size_a) == 0)
			rra(stack, 0);
	else
		while (stack->a[0] != min_value && ft_checked_sorted(stack->a,
				stack->size_a) == 0)
			ra(stack, 0);
}

void	selection_sort(t_stack *stack)
{
	int	i;
	int	min_index;
	int	temp;
	int	size;

	i = 0;
	size = stack->size_a;
	while (i < size && ft_checked_sorted(stack->a, stack->size_a) == 0)
	{
		min_index = find_min_index(stack->a, stack->size_a);
		temp = stack->a[min_index];
		if (stack->a[0] != temp && stack->size_a > 1)
			r_or_rr(stack, temp, min_index);
		if (ft_checked_sorted(stack->a, stack->size_a) == 0)
			pb(stack);
		i++;
	}
	while (stack->size_b > 0)
		pa(stack);
}
