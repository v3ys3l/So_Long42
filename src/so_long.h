/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:05:31 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/16 03:36:33 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define TILE_SIZE 64
# define KEY_W 119     // W tuşu
# define KEY_A 97      // A tuşu
# define KEY_S 115     // S tuşu
# define KEY_D 100     // D tuşu
# define KEY_ESC 65307 // ESC tuşu
# define KEY_X 17      // ekrandaki X tuşu

typedef struct s_game
{
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		total_coins;
	int		coins_counter;
	int		**visited;
	int		move_steps;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;
}			t_game;

int			handle_input(int key, t_game *game);
void		draw_map(t_game *game);
char		**read_map(const char *filename, t_game *game);
void		load_images(t_game *game);
char		*ft_strdup(const char *str);
int			check_move(t_game *game, int new_x, int new_y);
int			check_accessibility(t_game *mlx_s);
int			check_rectangular_map(t_game *game);
void		ft_clean(t_game *game);
void		*ft_memset(void *ptr, int value, size_t num);
int			check_map_exists(t_game *game);
int			check_required_elements(t_game *game);
int			check_invalid_characters(t_game *game);
int			check_line_lengths(t_game *game);
int			game_exit(t_game *game);
int			validate_map(t_game *game);
int			check_no_border_zero(t_game *game);
int			allocate_and_start_dfs(t_game *game);
int			check_map_and_free(t_game *game);
void		process_line(char *line, t_game *game);
#endif
