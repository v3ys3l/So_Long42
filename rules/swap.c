/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:50:05 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/24 12:01:02 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	sa(t_stack *stack, int print)
{
	int	tmp;

	if (stack->size_a > 1)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
		if (!print)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack *stack, int print)
{
	int	tmp;

	if (stack->size_b > 1)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
		if (!print)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack *stack)
{
	sa(stack, 1);
	sb(stack, 1);
	write(1, "ss\n", 1);
}
