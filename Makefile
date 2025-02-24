# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 16:44:23 by vbicer            #+#    #+#              #
#    Updated: 2025/02/24 17:29:38 by vbicer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L./libft -lft


SRCS = rules/push.c\
       rules/reverse_rotate.c\
       rules/rotate.c\
       rules/swap.c\
       free.c\
       sort1.c\
       sort2.c\
       utils.c\
       push_swap.c

OBJS = $(SRCS:.c=.o)



all: libs $(NAME)



$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libs:
	make -C ./libft

clean:
	rm -f $(OBJS)
	make clean -C ./libft



fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft


re: fclean all

.PHONY: all clean fclean re libs
