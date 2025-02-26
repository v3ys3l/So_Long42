/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:20:51 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/18 13:05:07 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../minilibx-linux/mlx.h"
#include "./so_long.h"

static void	ft_clean_images(t_game *game)
{
	if (game->img_coin)
	{
		mlx_destroy_image(game->mlx, game->img_coin);
		game->img_coin = NULL;
	}
	if (game->img_exit)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = NULL;
	}
	if (game->img_floor)
	{
		mlx_destroy_image(game->mlx, game->img_floor);
		game->img_floor = NULL;
	}
	if (game->img_player)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = NULL;
	}
	if (game->img_wall)
	{
		mlx_destroy_image(game->mlx, game->img_wall);
		game->img_wall = NULL;
	}
}

static void	ft_clean_map_and_window(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
	if (game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
}

static void	ft_clean_display_and_visited(t_game *game)
{
	int	i;

	i = 0;
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game->visited)
	{
		while (i < game->map_height)
		{
			if (game->visited[i])
			{
				free(game->visited[i]);
				game->visited[i] = NULL;
			}
			i++;
		}
		free(game->visited);
		game->visited = NULL;
	}
}

void	ft_clean(t_game *game)
{
	if (!game)
		return ;
	ft_clean_images(game);
	ft_clean_map_and_window(game);
	ft_clean_display_and_visited(game);
}
