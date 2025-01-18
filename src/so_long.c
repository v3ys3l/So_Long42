/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:05:29 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/18 17:01:12 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "so_long.h"

static int	initialize_game(t_game *game, char *map_file)
{
	game->map = read_map(map_file, game);
	if (!game->map)
	{
		ft_clean(game);
		return (0);
	}
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
		return (game_exit(game), 0);
	}
	return (1);
}

static void	start_game(t_game *game)
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
	mlx_hook(game->win, WINDOW_X, 0, game_exit, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		ext_len;

	game = (t_game){0};
	if (ac != 2)
	{
		ft_printf("You must specify the map file.\n");
		return (1);
	}
	ext_len = ft_strlen(av[1]);
	if (!(av[1][ext_len - 1] == 'r') || !(av[1][ext_len - 2] == 'e')
		|| !(av[1][ext_len - 3] == 'b') || !(av[1][ext_len - 4] == '.'))
		return (ft_printf("the file extension is incorrect\n"), 1);
	if (!initialize_game(&game, av[1]))
	{
		get_next_line(-1);
		ft_clean(&game);
		return (1);
	}
	start_game(&game);
	get_next_line(-1);
	return (0);
}
