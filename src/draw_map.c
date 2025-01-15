/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:45:09 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/16 01:05:39 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "so_long.h"

void	draw_tile(t_game *game, int x, int y, char tile)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
		* TILE_SIZE, y * TILE_SIZE);
	if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_coin, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_tile(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
	ft_printf("Steps: %d\n", game->move_steps);
}
