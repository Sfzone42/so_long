# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilusion <email@example.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 12:34:56 by ilusion           #+#    #+#              #
#    Updated: 2024/07/10 12:34:56 by ilusion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I. -I./minilibx-linux

NAME = so_long

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = game_main.c move_hook.c true_way.c render_window.c utils.c vrific_map.c read_map_valid.c ft_utilz.c 
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./minilibx-linux -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
