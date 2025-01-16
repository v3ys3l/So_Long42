/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:05:25 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/16 03:31:40 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../ft_printf/ft_printf.h"
#include "so_long.h"

int	check_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= game->map_width
		|| new_y >= game->map_height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'E')
		return (2);
	if (game->map[new_y][new_x] == 'C')
		return (3);
	return (1);
}

void	load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "Sprites/wall.xpm",
			&img_width, &img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "Sprites/floor.xpm",
			&img_width, &img_height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "Sprites/rabbit.xpm",
			&img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "Sprites/cave.xpm",
			&img_width, &img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "Sprites/player.xpm",
			&img_width, &img_height);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_coin || !game->img_exit)
	{
		ft_printf("\nThe images could not be loaded!\n");
		ft_clean(game);
		exit(1);
	}
	else
		ft_printf("The images were uploaded correctly.\n");
}
