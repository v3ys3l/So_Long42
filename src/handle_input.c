/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:51:19 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/18 16:32:03 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "so_long.h"

static void	update_game_state(t_game *game, int new_x, int new_y,
		int move_result)
{
	if (!(game->map[game->player_y][game->player_x] == 'E'))
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	if (move_result == 1 || move_result == 3)
	{
		game->map[new_y][new_x] = 'P';
		if (move_result == 3)
		{
			game->coins_counter++;
			ft_printf("coin: %d\n", game->coins_counter);
			ft_printf("total coin: %d\n", game->total_coins);
		}
	}
	if ((game->coins_counter == game->total_coins) && move_result == 2)
	{
		ft_printf("\nCongratulations! You won!\n");
		game_exit(game);
	}
	game->move_steps++;
	draw_map(game);
}

static void	process_move(t_game *game, int keycode, int new_x, int new_y)
{
	int	move_result;

	move_result = check_move(game, new_x, new_y);
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
	{
		if (move_result)
			update_game_state(game, new_x, new_y, move_result);
	}
}

int	handle_input(int keycode, t_game *game)//
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_ESC)
		return (ft_printf("\nGame closed by ESC key.\n"), game_exit(game));
	if (keycode == KEY_W)
		new_y--;
	else if (keycode == KEY_S)
		new_y++;
	else if (keycode == KEY_A)
		new_x--;
	else if (keycode == KEY_D)
		new_x++;
	process_move(game, keycode, new_x, new_y);
	return (0);
}
