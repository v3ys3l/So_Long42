/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:09:36 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/24 13:01:44 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	creat_stack(char **tmp, t_stack *stack)
{
	int	i;

	i = -1;
	stack->size_a = ft_prtsize(tmp);
	if (stack->size_a < 1)
		ft_error("Error\n", stack, stack->flag);
	stack->size_b = 0;
	stack->a = (int *)malloc(sizeof(int) * stack->size_a);
	if (!stack->a)
		ft_error("Error\nMalloc failed", stack, stack->flag);
	stack->b = (int *)malloc(sizeof(int) * stack->size_a);
	if (!stack->b)
		ft_error("Error\nMalloc failed", stack, stack->flag);
	while (tmp[++i])
	{
		stack->num = ft_strtrim(tmp[i], " ");
		stack->a[i] = ft_ps_atoi(stack->num, stack);
		free(stack->num);
	}
	stack->num = NULL;
	repeated_num(stack);
}

void	init_data(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
	stack->num = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->flag = 0;
}

void	ft_sort(t_stack *stack, int size)
{
	if (ft_checked_sorted(stack->a, stack->size_a) == 0)
	{
		if (size == 2)
			sa(stack, 0);
		else if (size == 3)
			ft_sort_three(stack);
		else if (stack->size_a <= 32)
			selection_sort(stack);
		else
		{
			index_stack(stack->a, stack->size_a, stack);
			radix_sort(stack);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac == 1)
		return (0);
	av++;
	init_data(&stack);
	if (ac == 2)
	{
		stack.tmp = ft_split(av[0], ' ');
		if (!stack.tmp)
			ft_error("Error\nMalloc failed", &stack, 0);
		stack.flag = 1;
		creat_stack(stack.tmp, &stack);
	}
	else
		creat_stack(av, &stack);
	if (stack.flag == 1)
		ft_free(stack.tmp);
	ft_sort(&stack, stack.size_a);
	free(stack.a);
	free(stack.b);
}
