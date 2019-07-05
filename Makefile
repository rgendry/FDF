# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/26 16:27:43 by rgendry           #+#    #+#              #
#    Updated: 2019/07/02 15:45:02 by rgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_SEARCH = src/*.c main.c

SRC = $(wildcard $(SRC_SEARCH))

OBJ = $(SRC:.c=.o)

HEADERS = -I include -I libft -I minilibx

LIBFLAGS = -L libft -lft

MLXFLAGS = -L minilibx -lmlx -framework OpenGL -framework AppKit

IMFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) libft libmlx
	gcc $(OBJ) -o $@ $(LIBFLAGS) $(MLXFLAGS)

%.o: %.c
	gcc -c $< -o $@ $(IMFLAGS) $(HEADERS) -g

.PHONY: libft
libft:
	make -C libft

.PHONY: libmlx
libmlx:
	make -C minilibx

.PHONY: clean
clean:
	make clean -C libft
	make clean -C minilibx
	rm -Rf $(OBJ)

.PHONY: fclean
fclean: clean
	make fclean -C libft
	make fclean -C minilibx
	rm -Rf $(NAME)

.PHONY: re
re: fclean all
