/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:27:01 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/18 13:36:48 by vbicer           ###   ########.fr       */
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

static int	check_horizontal_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] == '0' || game->map[game->map_height - 1][i] == '0'
			|| game->map[0][i] == 'E' || game->map[game->map_height
			- 1][i] == 'E' || game->map[0][i] == 'C'
			|| game->map[game->map_height - 1][i] == 'C'
			|| game->map[0][i] == 'P' || game->map[game->map_height
			- 1][i] == 'P')
		{
			ft_printf("There is a '0,C,E,P' at the top or base of the map!\n");
			return (ft_clean(game), 0);
		}
		i++;
	}
	return (1);
}

static int	check_vertical_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] == '0' || game->map[i][game->map_width - 1] == '0'
			|| game->map[i][0] == 'E' || game->map[i][game->map_width
			- 1] == 'E' || game->map[i][0] == 'C'
			|| game->map[i][game->map_width - 1] == 'C'
			|| game->map[i][0] == 'P' || game->map[i][game->map_width
			- 1] == 'P')
		{
			ft_printf("There is a '0,C,E,P' on the edge of the map!\n");
			return (ft_clean(game), 0);
		}
		i++;
	}
	return (1);
}

int	check_no_border_zero(t_game *game)
{
	if (!check_horizontal_borders(game))
		return (0);
	if (!check_vertical_borders(game))
		return (0);
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
