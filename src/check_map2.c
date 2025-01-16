/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:27:01 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/16 03:46:35 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "so_long.h"

int	check_rectangular_map(t_game *game)
{
	int	i;
	int	len;

	i = 1;
	len = game->map_width;
	while (i < game->map_height)
	{
		if ((int)ft_strlen(game->map[i]) != len)
		{
			ft_printf("The map is not rectangular!\n");
			ft_clean(game);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_no_border_zero(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] == '0' || game->map[game->map_height - 1][i] == '0')
		{
			ft_printf("There is a '0' on the edge of the map!\n");
			ft_clean(game);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] == '0' || game->map[i][game->map_width - 1] == '0')
		{
			ft_printf("There is a '0' on the edge of the map!\n");
			ft_clean(game);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_accessibility(t_game *game)
{
	if (!allocate_and_start_dfs(game))
		return (0);
	game->coins_counter = 0;
	if (!check_map_and_free(game))
		return (0);
	return (1);
}
