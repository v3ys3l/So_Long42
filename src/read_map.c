/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:56:48 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/16 02:41:47 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "so_long.h"

void	process_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
		{
			game->player_x = i;
			game->player_y = game->map_height;
		}
		if (line[i] == 'C')
			game->total_coins++;
		i++;
	}
}

int	validate_map(t_game *game)
{
	if (!game || !game->map)
		return (0);
	if (!check_map_exists(game))
		return (ft_printf("Your map is not valid!\n"), 0);
	if (!check_rectangular_map(game))
		return (0);
	if (!check_required_elements(game))
		return (0);
	if (!check_invalid_characters(game))
		return (0);
	if (!check_line_lengths(game))
		return (0);
	if (!check_no_border_zero(game))
		return (0);
	return (1);
}
