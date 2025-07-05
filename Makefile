# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 19:49:11 by lsurco-t          #+#    #+#              #
#    Updated: 2025/07/05 21:43:26 by lsurco-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
MLX42_DIR = ./MLX42
OBJ_DIR = obj
SRC_DIR = src
LIBFT = $(LIBFT_DIR)/libft.a
MLX42 = $(MLX42_DIR)/build/libmlx42.a
HEADERS = -I./utils -I$(LIBFT_DIR) -I$(MLX42_DIR)/include


LIBS = $(MLX42) $(LIBFT) -ldl -lglfw -pthread -lm
SRC = $(SRC_DIR)/so_long.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(OBJ_DIR) $(LIBFT) $(MLX42) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Created object directory$(RESET)"

$(LIBFT):
	@echo "$(BLUE)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft built successfully$(RESET)"

$(MLX42):
	@echo "$(BLUE)Building MLX42...$(RESET)"
	@if [ ! -d "$(MLX42_DIR)/build" ]; then \
		cmake -B $(MLX42_DIR)/build $(MLX42_DIR); \
	fi
	@make -C $(MLX42_DIR)/build -j4
	@echo "$(GREEN)MLX42 built successfully$(RESET)"

$(NAME): $(OBJ) $(LIBFT) $(MLX42)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)
	@echo "$(GREEN)$(NAME) built successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$(GREEN)Compiled: $(notdir $<)$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)Cleaned object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX42_DIR)/build
	@echo "$(RED)Full clean completed$(RESET)"

re: fclean all

.PHONY: all clean fclean re