/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:24:22 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/16 01:07:20 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "so_long.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dup;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_strlen((char *)str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*byte_ptr;
	unsigned char	byte_value;

	byte_ptr = (unsigned char *)ptr;
	byte_value = (unsigned char)value;
	while (num--)
	{
		*byte_ptr = byte_value;
		byte_ptr++;
	}
	return (ptr);
}

int	game_exit(t_game *game)
{
	if (game)
		ft_clean(game);
	exit(0);
	return (0);
}
