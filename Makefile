# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 15:18:17 by eardingh          #+#    #+#              #
#    Updated: 2022/05/13 15:06:49 by eardingh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

CC = gcc -o $(NAME)

NAME = so_long

CFLAGS = -Wall -Werror -Wextra -g


OBJS		= $(SRCS:%.c=%.o)

SRCS = src/main.c \
		src/file.c \
		src/error_map.c \
		src/character.c \
		src/map.c \
		src/img.c \
		src/game.c \
		src/mov.c \
		src/utils.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		-L./miniliBX/ -framework OpenGL -framework AppKit miniliBX/libmlx.a \

all: $(NAME)
	

${NAME}: 
	@${MAKE} -C ./libft
	@${MAKE} -C ./miniliBX
	${CC} ${CFLAGS} ${SRCS} ${LIBFT} 
	
clean:
	rm -f $(OBJS)
	rm -f $(NAME)

fclean: clean
	rm -f ${OBJS} $(NAME)

re: fclean ${NAME}
