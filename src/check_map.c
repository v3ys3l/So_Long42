/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:51:46 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/16 03:46:13 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "so_long.h"

static void	dfs(int x, int y, t_game *game)
{
	if (!game || !game->map || !game->visited)
		return ;
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	if (!game->map[y] || !game->visited[y])
		return ;
	if (game->map[y][x] == '1' || game->visited[y][x] == 1)
		return ;
	if (game->map[y][x] == 'C' || game->map[y][x] == 'E')
		game->coins_counter++;
	game->visited[y][x] = 1;
	dfs(x + 1, y, game);
	dfs(x - 1, y, game);
	dfs(x, y + 1, game);
	dfs(x, y - 1, game);
}

static int	allocate_visited_memory(t_game *game)
{
	int	i;

	if (game->map_height <= 0 || game->map_width <= 0)
		return (ft_printf("Invalid map dimensions!\n"), 0);
	game->visited = malloc(game->map_height * sizeof(int *));
	if (!game->visited)
		return (ft_printf("Memory allocation failed!\n"), 0);
	i = 0;
	while (i < game->map_height)
	{
		game->visited[i] = malloc(game->map_width * sizeof(int));
		if (!game->visited[i])
		{
			while (--i >= 0)
				free(game->visited[i]);
			free(game->visited);
			return (ft_printf("Memory allocation failed!\n"), 0);
		}
		ft_memset(game->visited[i], 0, game->map_width * sizeof(int));
		i++;
	}
	return (1);
}

static int	start_dfs_and_validate_position(t_game *game)
{
	int	i;

	if (game->player_x < 0 || game->player_x >= game->map_width
		|| game->player_y < 0 || game->player_y >= game->map_height)
	{
		ft_printf("Invalid player position!\n");
		i = 0;
		while (i < game->map_height)
		{
			free(game->visited[i]);
			i++;
		}
		free(game->visited);
		return (0);
	}
	dfs(game->player_x, game->player_y, game);
	return (game->coins_counter -1 == game->total_coins);
}

int	allocate_and_start_dfs(t_game *game)
{
	if (!allocate_visited_memory(game))
		return (0);
	return (start_dfs_and_validate_position(game));
}

int	check_map_and_free(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->visited[i]);
		game->visited[i] = NULL;
		i++;
	}
	free(game->visited);
	game->visited = NULL;
	return (1);
}
