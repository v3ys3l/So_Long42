/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:48:04 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/24 11:48:33 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	ra(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	if (stack->size_a > 1)
	{
		tmp = stack->a[0];
		i = -1;
		while (++i < stack->size_a - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = tmp;
		if (!print)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	if (stack->size_b > 1)
	{
		tmp = stack->b[0];
		i = -1;
		while (++i < stack->size_b - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = tmp;
		if (!print)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack *stack)
{
	ra(stack, 1);
	rb(stack, 1);
	write(1, "rr\n", 3);
}
