/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:10:36 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/16 00:48:09 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_malloc(int n)
{
	char	*str;

	str = malloc(sizeof(char) * n);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_creat(int fd, char *buffer)
{
	char	*temp;
	int		size;

	temp = my_malloc((BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	size = 1;
	while (!ft_strchr(buffer) && size != 0)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size == -1)
			return (free(temp), NULL);
		temp[size] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	return (free(temp), buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd == GNL_CLEAR)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_creat(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_new_str(buffer);
	if (!buffer && !line)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

void	ft_gnl_clear(int fd)
{
	static char	*buffer;

	if (fd >= 0 && buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}
