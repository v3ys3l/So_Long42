# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 18:15:52 by vbicer            #+#    #+#              #
#    Updated: 2025/01/16 02:40:27 by vbicer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -L./ft_printf -lftprintf -L./get_next_line -lgetnext
MLX = -Lminilibx-linux -lmlx -lX11 -lXext -lm

SRC_DIR = src/

SRC_FILES = check_map.c \
			check_map2.c \
			check_map3.c \
			draw_map.c \
			handle_input.c \
			map_control.c \
			read_map.c \
			read_map2.c \
			so_long_utils.c\
			clean.c \
			so_long.c


SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))


OBJS = $(SRCS:.c=.o)


all: libs $(NAME)


libs:
	make -C ./ft_printf
	make -C ./get_next_line


$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(MLX) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)
	make clean -C ./ft_printf
	make clean -C ./get_next_line


fclean: clean
	rm -f $(NAME)
	make fclean -C ./ft_printf
	make fclean -C ./get_next_line


re: fclean all

.PHONY: all clean fclean re libs
