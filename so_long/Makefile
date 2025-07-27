# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 16:49:20 by viceda-s          #+#    #+#              #
#    Updated: 2025/07/22 14:16:05 by viceda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========================
# 		CONFIGURATION
# =========================

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_PATH	= minilibx-linux/
MLX_LIB		= $(MLX_PATH)libmlx.a
MLX_FLAGS	= -Lminilibx-linux -lmlx -lXext -lX11 -lm
LIBFT_PATH	= libft/
LIBFT_LIB	= $(LIBFT_PATH)libft.a


# =========================
# 		SOURCE FILES
# =========================

SRCS		= so_long.c \
			src/init.c \
			src/position.c \
			src/map_loader.c \
			src/map_validator.c \
			src/path_validator.c \
			src/render.c \
			src/player.c \
			src/enemy.c \
			src/game_logic.c \
			src/cleanup.c

# =========================
# 		OBJECT FILES
# =========================

OBJS		= $(SRCS:.c=.o)

# =========================
#         COLORS
# =========================

GREEN		= \033[0;32m
YELLOW		= \033[1;33m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

# =========================
#       ASCII ART
# =========================

# =========================
#          RULES
# =========================

all: $(NAME)

ascii:
	@echo "$(BLUE)"
	@echo "███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ "
	@echo "██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ "
	@echo "███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗"
	@echo "╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║"
	@echo "███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝"
	@echo "╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ "
	@echo "$(RESET)"
	@echo "$(YELLOW)                 🎮 BOMBERMAN STYLE GAME 🎮$(RESET)"
	@echo "$(GREEN)             Created by viceda-s @ 42 Luxembourg$(RESET)"
	@echo ""

$(NAME): ascii $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	@echo "$(YELLOW)[./] Building $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_PATH) -lft -o $(NAME)
	@echo "$(GREEN)[OK] $(NAME) compiled successfully!$(RESET)"
	@echo "$(BLUE)🎮 Game ready! Run with: ./$(NAME) <map.ber>$(RESET)"

$(MLX_LIB):
	@echo "$(YELLOW)[./] Compiling minilibx...$(RESET)"
	@make -C $(MLX_PATH)
	@echo "$(GREEN)[OK] minilibx compiled successfully!$(RESET)"

$(LIBFT_LIB):
	@echo "$(YELLOW)[./] Compiling libft...$(RESET)"
	@make -C $(LIBFT_PATH)
	@echo "$(GREEN)[OK] libft compiled successfully!$(RESET)"

clean:
	@echo "$(RED)[./] Cleaning object files...$(RESET)"
	rm -f $(OBJS)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)
	@echo "$(GREEN)[OK] Object files removed!$(RESET)"

fclean: clean
	@echo "$(RED)[./] Cleaning so_long...$(RESET)"
	rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(GREEN)[OK] Full clean completed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re ascii

