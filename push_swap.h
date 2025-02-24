/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:57:33 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/24 12:57:47 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	char	**tmp;
	int		*a;
	int		*b;
	char	*num;
	int		size_a;
	int		size_b;
	int		flag;
}			t_stack;

void		index_stack(int *stack, int size, t_stack *s);

/*RULES*/
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		rra(t_stack *stack, int print);
void		rrb(t_stack *stack, int print);
void		rrr(t_stack *stack);
void		ra(t_stack *stack, int print);
void		rb(t_stack *stack, int print);
void		rr(t_stack *stack);
void		sa(t_stack *stack, int print);
void		sb(t_stack *stack, int print);
void		ss(t_stack *stack);

/*FREE AND ERROR*/
void		ft_free(char **str);
void		ft_error(char *str, t_stack *stack, int flag);

/*SORTS*/
void		radix_sort(t_stack *stack);
void		ft_sort_three(t_stack *s);
void		ft_sort(t_stack *stack, int size);
void		selection_sort(t_stack *stack);

/*UTILS*/
void		repeated_num(t_stack *stack);
int			ft_prtsize(char **ptr);
int			ft_ps_atoi(char *str, t_stack *stack);
int			ft_checked_sorted(int *stack, int size);

#endif
