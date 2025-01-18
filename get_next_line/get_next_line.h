/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:10:43 by vbicer            #+#    #+#             */
/*   Updated: 2025/01/18 11:01:05 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
int		ft_strchr(char *s);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_line(char *left_str);
char	*ft_new_str(char *left_str);
char	*get_next_line(int fd);
char	*my_malloc(int n);

#endif
