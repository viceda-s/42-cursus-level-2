# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 19:29:59 by viceda-s          #+#    #+#              #
#    Updated: 2025/07/10 21:14:47 by viceda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========================
#		CONFIGURATION
# =========================

NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCDIR = .
OBJDIR = obj

# =========================
#		SOURCE FILES
# =========================

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

# =========================
#		BONUS FILES
# =========================

SRCS_CLIENT_BONUS = client_bonus.c
SRCS_SERVER_BONUS = server_bonus.c

# =========================
#		OBJECT FILES
# =========================

OBJS_CLIENT = $(SRCS_CLIENT:%.c=$(OBJDIR)/%.o)
OBJS_SERVER = $(SRCS_SERVER:%.c=$(OBJDIR)/%.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:%.c=$(OBJDIR)/%.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:%.c=$(OBJDIR)/%.o)

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

all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER) 

bonus: $(LIBFT) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	@echo "$(BLUE)[./] Compiling client executable...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(LIBFT)
	@echo "$(GREEN)[OK] Client compiled successfully!$(RESET)"

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	@echo "$(BLUE)[./] Compiling server executable...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(LIBFT)
	@echo "$(GREEN)[OK] Server compiled successfully!$(RESET)"

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
	@echo "$(BLUE)[./] Compiling client bonus executable...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJS_CLIENT_BONUS) $(LIBFT)
	@echo "$(GREEN)[OK] Client bonus compiled successfully!$(RESET)"

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
	@echo "$(BLUE)[./] Compiling server bonus executable...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJS_SERVER_BONUS) $(LIBFT)
	@echo "$(GREEN)[OK] Server bonus compiled successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(YELLOW)[INFO] Compiling $<...$(RESET)"
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED) Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@find $(LIBFT_DIR) -type f -name "*.o" -delete
	@echo -e "$(GREEN)[OK] Object files removed!$(RESET)"

fclean: clean
	@echo "$(RED) Cleaning executables...$(RESET)"
	@rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo -e "$(GREEN)[OK] Executables removed!$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
