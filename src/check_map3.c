/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:22 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/16 01:03:26 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "so_long.h"

int	check_map_exists(t_game *game)
{
	if (!game->map || game->map_height == 0 || game->map_width == 0)
	{
		ft_printf("Harita bulunamadı!\n");
		return (0);
	}
	return (1);
}

static int	count_map_elements(t_game *game, int *player_count, int *exit_count,
		int *collectible_count)
{
	int	i;
	int	j;

	*player_count = 0;
	*exit_count = 0;
	*collectible_count = 0;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'E')
				(*exit_count)++;
			if (game->map[i][j] == 'C')
				(*collectible_count)++;
			if (game->map[i][j] == 'P')
				(*player_count)++;
			j++;
		}
		i++;
	}
	return (1);
}

int	check_required_elements(t_game *game)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	if (!count_map_elements(game, &player_count, &exit_count,
			&collectible_count))
		return (ft_printf("The count of map elements failed.\n"),
			ft_clean(game), 0);
	if (player_count != 1)
		return (ft_printf("There are multiple or no players on the map.\n"),
			ft_clean(game), 0);
	if (exit_count != 1)
		return (ft_printf("Multiple or no exits on the map.\n"), ft_clean(game),
			0);
	if (collectible_count == 0)
		return (ft_printf("There is no 'C' (Collectible item) on the map!\n"),
			ft_clean(game), 0);
	return (1);
}

int	check_invalid_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E')
			{
				ft_printf("Invalid character was found on the map: '%c'\n",
					game->map[i][j]);
				ft_clean(game);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_line_lengths(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->map_height)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_width)
		{
			ft_printf("Map line lengths are inconsistent!\n");
			ft_clean(game);
			return (0);
		}
		i++;
	}
	return (1);
}
