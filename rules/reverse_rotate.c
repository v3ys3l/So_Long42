/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:47:21 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/24 12:58:02 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	rra(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	if (stack->size_a > 1)
	{
		tmp = stack->a[stack->size_a - 1];
		i = stack->size_a;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[i] = tmp;
		if (!print)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	if (stack->size_b > 1)
	{
		tmp = stack->b[stack->size_b - 1];
		i = stack->size_b;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[i] = tmp;
		if (!print)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *stack)
{
	ra(stack, 1);
	rb(stack, 1);
	write(1, "rrr\n", 4);
}
