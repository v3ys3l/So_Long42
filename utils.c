/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:07:33 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/24 12:07:35 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	repeated_num(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = 0;
		while (j < stack->size_a)
		{
			if (stack->a[i] == stack->a[j] && i != j)
				ft_error("Error\n", stack, stack->flag);
			j++;
		}
		i++;
	}
}

int	ft_prtsize(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		;
	return (i);
}

int	ft_ps_atoi(char *str, t_stack *stack)
{
	int				sing;
	long long int	res;

	res = 0;
	sing = 1;
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sing = -1;
		str++;
	}
	if (*str == '\0')
		ft_error("Error\n", stack, stack->flag);
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			ft_error("Error\n", stack, stack->flag);
		res = (res * 10) + (*str - '0');
		str++;
	}
	if ((res * sing < -2147483648 || res * sing > 2147483647))
		ft_error("Error\n", stack, stack->flag);
	return (res * sing);
}

int	ft_checked_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
