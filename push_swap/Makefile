# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 11:12:11 by viceda-s          #+#    #+#              #
#    Updated: 2025/07/09 16:08:14 by viceda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========================
#		CONFIGURATION
# =========================

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

INCLUDES	= -Iinclude -Ilibft/include

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_DIR		= srcs
COMM_DIR	= $(SRC_DIR)/commands
PS_DIR	= $(SRC_DIR)/push_swap

# =========================
#		SOURCE FILES
# =========================

SRCS		= \
$(COMM_DIR)/push.c \
$(COMM_DIR)/reverse_rotate.c \
$(COMM_DIR)/rotate.c \
$(COMM_DIR)/sort_stacks.c \
$(COMM_DIR)/sort_small.c \
$(COMM_DIR)/sort_utils.c \
$(COMM_DIR)/swap.c \
$(PS_DIR)/handle_errors.c \
$(PS_DIR)/init_a_to_b.c \
$(PS_DIR)/init_b_to_a.c \
$(PS_DIR)/push_swap.c \
$(PS_DIR)/split.c \
$(PS_DIR)/stack_init.c \
$(PS_DIR)/stack_utils.c

# =========================
#		OBJECT FILES
# =========================

OBJS		= $(SRCS:.c=.o)

# =========================
#		COLORS
# =========================

GREEN		= \033[0;32m
YELLOW		= \033[1;33m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

# =========================
#		RULES
# =========================

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo -e "$(BLUE)[INFO] Building $(NAME) executable...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo -e "$(GREEN)[OK] Executable compiled successfully!$(RESET)"

$(LIBFT):
	@echo -e "$(BLUE)[INFO] Building Libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@echo -e "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo -e "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@find $(LIBFT_DIR) -type f -name "*.o" -delete
	@echo -e "$(GREEN)[OK] Object files removed!$(RESET)"

fclean: clean
	@echo -e "$(RED)Cleaning executable...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo -e "$(GREEN)[OK] Full clean completed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
