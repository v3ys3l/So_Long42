# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 18:14:50 by vbicer            #+#    #+#              #
#    Updated: 2025/01/16 00:53:08 by vbicer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GET_NEXT_LINE_NAME = libgetnext.a
GET_NEXT_LINE_SRC = get_next_line.c\
get_next_line_utils.c\
utils2.c
GET_NEXT_LINE_OBJ = $(GET_NEXT_LINE_SRC:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


all: $(GET_NEXT_LINE_NAME)

$(GET_NEXT_LINE_NAME): $(GET_NEXT_LINE_OBJ)
	ar rcs $(GET_NEXT_LINE_NAME) $(GET_NEXT_LINE_OBJ)


clean:
	$(RM) $(GET_NEXT_LINE_OBJ)


fclean: clean
	$(RM) $(GET_NEXT_LINE_NAME)


re: fclean all

.PHONY: all clean fclean re
