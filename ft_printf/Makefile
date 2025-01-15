# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 21:37:56 by vbicer            #+#    #+#              #
#    Updated: 2024/11/03 21:37:56 by vbicer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT_PRINTF_NAME = libftprintf.a
LIBFT_PRINTF_SRC = ft_printf_utils.c ft_printf.c ft_putchar.c
LIBFT_PRINTF_OBJ = $(LIBFT_PRINTF_SRC:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


all: $(LIBFT_PRINTF_NAME)

$(LIBFT_PRINTF_NAME): $(LIBFT_PRINTF_OBJ)
	ar rcs $(LIBFT_PRINTF_NAME) $(LIBFT_PRINTF_OBJ)


clean:
	$(RM) $(LIBFT_PRINTF_OBJ)


fclean: clean
	$(RM) $(LIBFT_PRINTF_NAME)


re: fclean all

.PHONY: all clean fclean re
