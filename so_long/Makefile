# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 11:29:36 by vivaz-ca          #+#    #+#              #
#    Updated: 2025/11/08 11:57:05 by vvazzs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCDIR = .
OBJDIR = objs
MLXDIR = ../.minilibx-linux
GNL_DIR = ./gnl
MAP_DIR = maps
TEXTURE_DIR = ../textures
PRINTF_DIR = ./my_printf

SRC = \
	$(SRCDIR)/main.c utils.c utils2.c player_movement.c create_map.c parsing.c free.c flood_fill.c movement_utils.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c \
	$(PRINTF_DIR)/printf_utils.c \
	$(PRINTF_DIR)/printf_utils2.c \
	$(PRINTF_DIR)/libft_functions.c \
	$(PRINTF_DIR)/ft_itoa.c

OBJS = $(SRC:../%.c=$(OBJDIR)/%.o)
OBJS := $(OBJS:./%.c=$(OBJDIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -L . -lmlx -lXext -lX11
INCLUDES = -I$(MLXDIR) -I$(GNL_DIR) -I. -I$(MAP_DIR) -I$(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: ../%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: ./%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

val:
	valgrind --leak-check=full --track-fds=yes --show-leak-kinds=all --track-origins=yes ./$(NAME) $(MAP_DIR)/subject_map.ber
	
lib:
	tar -xf minilibx-linux.tgz
	cd minilibx-linux && make CFLAGS="-O3 -std=gnu11"
	test -f libmlx.a
	rm -rf minilibx-linux


.PHONY: all clean fclean re
