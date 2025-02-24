/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:44:53 by vbicer            #+#    #+#             */
/*   Updated: 2024/11/30 00:39:28 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int a)
{
	if (a <= 127 && a >= 0)
		return (1);
	return (0);
}
