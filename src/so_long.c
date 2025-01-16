/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:05:29 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/16 03:38:07 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "so_long.h"

int	initialize_game(t_game *game, char *map_file)
{
	game->map = read_map(map_file, game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		game->mlx = NULL;
		ft_printf("Error initializing mlx\n");
		ft_clean(game);
		return (0);
	}
	if (!check_accessibility(game))
	{
		ft_printf("No valid way has been found!\n");
		game_exit(game);
	}
	if (!validate_map(game))
	{
		ft_printf("map is not correct!\n");
		game_exit(game);
		return (0);
	}
	return (1);
}

void	start_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "So Long");
	if (!game->win)
	{
		ft_printf("Error creating window\n");
		free(game->mlx);
		game->mlx = NULL;
		ft_clean(game);
		exit(1);
	}
	load_images(game);
	draw_map(game);
	mlx_key_hook(game->win, handle_input, game);
	mlx_hook(game->win, 17, 0, game_exit, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	if (argc != 2)
	{
		ft_printf("You must specify the map file.\n");
		return (1);
	}
	if (!initialize_game(&game, argv[1]))
	{
		get_next_line(GNL_CLEAR);
		return (1);
	}
	start_game(&game);
	get_next_line(GNL_CLEAR);
	return (0);
}
