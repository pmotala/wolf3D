# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmotala <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/06 16:47:52 by pmotala           #+#    #+#              #
#    Updated: 2018/08/23 10:08:28 by pmotala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3D
PATH_SRC = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = wolf3d.h

SRC =	read.c \
		render.c \
		main.c \
		functions.c \
		keyboard.c \
		raycasting.c \
		textures.c \
		image.c \

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean

norme:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(HEAD)
	make -C libft/ norme

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	
re: fclean all
