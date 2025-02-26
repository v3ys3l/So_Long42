/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 02:38:29 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/18 17:03:35 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "so_long.h"

static int	read_line_map(const char *filename)
{
	int		fd;
	int		i;
	int		len;
	char	a;

	fd = open(filename, O_RDONLY);
	i = 1;
	len = 0;
	while (i == 1)
	{
		i = read(fd, &a, 1);
		len++;
	}
	return (len);
}

static int	open_file_and_allocate_map(const char *filename, t_game *game,
		int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		ft_printf("The map file could not be opened\n");
		return (0);
	}
	game->map = malloc(sizeof(char *) * read_line_map(filename));
	if (!game->map)
	{
		close(*fd);
		return (0);
	}
	return (1);
}

static int	process_map_lines(int fd, t_game *game)
{
	char	*line;
	size_t	len;

	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (game->map_height == 0)
			game->map_width = ft_strlen(line);
		else if ((int)ft_strlen(line) != game->map_width)
			return (free(line), 0);
		game->map[game->map_height] = ft_strdup(line);
		if (!game->map[game->map_height])
			return (free(line), 0);
		process_line(line, game);
		free(line);
		line = get_next_line(fd);
		game->map_height++;
	}
	return (1);
}

static char	**close_and_return_map(int fd, t_game *game)
{
	close(fd);
	get_next_line(-1);
	if (game->map_height == 0)
	{
		free(game->map);
		ft_printf("Empty map file!\n");
		return (NULL);
	}
	return (game->map);
}

char	**read_map(const char *filename, t_game *game)
{
	int	fd;

	if (!open_file_and_allocate_map(filename, game, &fd))
		return (NULL);
	if (!process_map_lines(fd, game))
	{
		ft_clean(game);
		close(fd);
		ft_printf("Memory allocation or map format error!\n");
		return (NULL);
	}
	return (close_and_return_map(fd, game));
}
