# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 15:56:24 by viceda-s          #+#    #+#              #
#    Updated: 2026/01/07 18:16:22 by viceda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# =========================
#        CONFIGURATION
# =========================

NAME		= pipex
BONUS		= pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

INCLUDES	= -Iinc -Ilibft/include

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

OBJS_DIR	= obj
SRC_DIR		= src
BONUS_DIR	= $(SRC_DIR)/bonus

# =========================
#       SOURCE FILES
# =========================

SRC			= \
$(SRC_DIR)/path.c \
$(SRC_DIR)/pipex.c \
$(SRC_DIR)/utils.c

# =========================
#      BONUS FILES
# =========================

BONUS_SRC	= \
$(BONUS_DIR)/exec_bonus.c \
$(BONUS_DIR)/here_doc_bonus.c \
$(BONUS_DIR)/pipe_utils_bonus.c \
$(BONUS_DIR)/pipex_bonus.c

SHARED_SRC	= \
$(SRC_DIR)/path.c \
$(SRC_DIR)/utils.c

# =========================
#     OBJECT FILES
# =========================

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))
BONUS_OBJS	= $(addprefix $(OBJS_DIR)/, $(BONUS_SRC:.c=.o))
SHARED_OBJS	= $(addprefix $(OBJS_DIR)/, $(SHARED_SRC:.c=.o))

# Progress tracking
TOTAL_SRC	= $(words $(SRC))
BONUS_TOTAL	= $(words $(BONUS_SRC))
SHARED_TOTAL = $(words $(SHARED_SRC))
TOTAL_BONUS_FILES = $(shell echo $$(($(BONUS_TOTAL) + $(SHARED_TOTAL))))
CURRENT		= 0

# =========================
#         COLORS
# =========================

GREEN		= \033[0;32m
YELLOW		= \033[1;33m
RED			= \033[0;31m
BLUE		= \033[0;34m
BOLD		= \033[1m
RESET		= \033[0m

# =========================
#          RULES
# =========================

all: print_header $(NAME)

print_header:
	@echo "\033[38;5;33m"
	@echo "            ███                                "
	@echo "           ░░░                                 "
	@echo " ████████  ████  ████████   ██████  █████ █████"
	@echo "░░███░░███░░███ ░░███░░███ ███░░███░░███ ░░███ "
	@echo " ░███ ░███ ░███  ░███ ░███░███████  ░░░█████░  "
	@echo " ░███ ░███ ░███  ░███ ░███░███░░░    ███░░░███ "
	@echo " ░███████  █████ ░███████ ░░██████  █████ █████"
	@echo " ░███░░░  ░░░░░  ░███░░░   ░░░░░░  ░░░░░ ░░░░░ "
	@echo " ░███            ░███               by viceda-s"
	@echo " █████           █████                         "
	@echo "░░░░░           ░░░░░                          "
	@echo ""

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/$(SRC_DIR)
	@mkdir -p $(OBJS_DIR)/$(BONUS_DIR)

$(NAME): $(OBJS_DIR) $(LIBFT)
	@$(MAKE) build_pipex --no-print-directory

build_pipex: $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(BOLD)$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(eval IS_BONUS=$(filter bonus,$(MAKECMDGOALS)))
	@$(eval TARGET=$(if $(IS_BONUS),pipex (bonus),pipex))
	@$(eval TOTAL=$(if $(IS_BONUS),$(TOTAL_BONUS_FILES),$(TOTAL_SRC)))
	@$(eval BONUS_COUNT=$(shell find $(OBJS_DIR)/$(BONUS_DIR) -name '*.o' 2>/dev/null | wc -l))
	@$(eval SHARED_COUNT=$(shell find $(OBJS_DIR)/src -name '*.o' 2>/dev/null | wc -l))
	@$(eval CURRENT=$(if $(IS_BONUS),$(shell echo $$(($(BONUS_COUNT) + $(SHARED_COUNT)))),$(shell find $(OBJS_DIR) -name '*.o' 2>/dev/null | wc -l)))
	@$(eval PERCENT=$(shell if [ $(CURRENT) -ge $(TOTAL) ]; then echo 100; else echo $$(($(CURRENT) * 100 / $(TOTAL))); fi))
	@$(eval FILLED=$(shell echo $$(($(PERCENT) / 2))))
	@$(eval EMPTY=$(shell echo $$((50 - $(FILLED)))))
	@if [ $(CURRENT) -eq 0 ]; then printf "\n$(BOLD)$(BLUE)Compiling $(TARGET):$(RESET)\n"; fi
	@printf "[$(GREEN)"
	@for i in $$(seq 1 $(FILLED)); do printf "█"; done
	@printf "$(RESET)"
	@for i in $$(seq 1 $(EMPTY)); do printf "░"; done
	@printf "$(RESET)] $(YELLOW)%3d%%$(RESET) %-25s\r" $(PERCENT) "$(notdir $<)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@if [ $(CURRENT) -eq $$(($(TOTAL) - 1)) ]; then \
		printf "[$(GREEN)"; \
		for i in $$(seq 1 50); do printf "█"; done; \
		printf "$(RESET)] $(GREEN)100%%$(RESET)                          \n"; \
	fi

bonus: clean_bonus_objs build_bonus

clean_bonus_objs:
	@$(RM) -r $(OBJS_DIR)/$(BONUS_DIR) $(OBJS_DIR)/$(SRC_DIR)

build_bonus: $(OBJS_DIR) $(LIBFT) $(BONUS_OBJS) $(SHARED_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(SHARED_OBJS) $(LIBFT) -o $(NAME)
	@printf "[$(GREEN)"
	@for i in $$(seq 1 50); do printf "█"; done
	@printf "$(RESET)] $(GREEN)100%%$(RESET)                          \n"
	@echo "$(BOLD)$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

clean:
	@printf "$(BOLD)$(RED)Cleaning:$(RESET)\n"
	@printf "[$(RED)██████████████████████████████████████████████████$(RESET)] $(YELLOW)Removing objects...$(RESET)\r"
	@$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory > /dev/null 2>&1
	@printf "[$(GREEN)██████████████████████████████████████████████████$(RESET)] $(GREEN)100%%$(RESET)                         \n"
	@echo "$(BOLD)$(GREEN)✓ Clean completed!$(RESET)"
	@echo ""

fclean: 
	@printf "\n$(BOLD)$(RED)Full cleaning:$(RESET)\n"
	@printf "[$(RED)█████████████████████████$(RESET)░░░░░░░░░░░░░░░░░░░░░░░░░] $(YELLOW) 50%%$(RESET) Removing objects...\r"
	@$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory > /dev/null 2>&1
	@printf "[$(RED)██████████████████████████████████████████████████$(RESET)] $(YELLOW)100%%$(RESET) Removing executables...\r"
	@$(RM) $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory > /dev/null 2>&1
	@printf "[$(GREEN)██████████████████████████████████████████████████$(RESET)] $(GREEN)100%%$(RESET)                             \n"
	@echo "$(BOLD)$(GREEN)✓ Full clean completed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus print_header
