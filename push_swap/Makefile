# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 11:12:11 by viceda-s          #+#    #+#              #
#    Updated: 2026/01/06 17:31:08 by viceda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========================
#        CONFIGURATION
# =========================

NAME		= push_swap
BONUS		= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

INCLUDES	= -Iinc -Ilibft/include

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

OBJS_DIR	= obj
SRCS_DIR	= srcs
BONUS_DIR	= bonus
COMM_DIR	= $(SRCS_DIR)/commands
PS_DIR		= $(SRCS_DIR)/push_swap

# =========================
#       SOURCE FILES
# =========================

SRCS		= \
$(COMM_DIR)/push.c \
$(COMM_DIR)/reverse_rotate.c \
$(COMM_DIR)/rotate.c \
$(COMM_DIR)/sort_stacks.c \
$(COMM_DIR)/sort_small.c \
$(COMM_DIR)/sort_utils.c \
$(COMM_DIR)/swap.c \
\
$(PS_DIR)/handle_errors.c \
$(PS_DIR)/init_a_to_b.c \
$(PS_DIR)/init_b_to_a.c \
$(PS_DIR)/push_swap.c \
$(PS_DIR)/split.c \
$(PS_DIR)/stack_init.c \
$(PS_DIR)/stack_utils.c

# =========================
#      BONUS FILES
# =========================

BONUS_SRCS	= \
$(BONUS_DIR)/checker.c \
$(BONUS_DIR)/checker_utils.c \
$(BONUS_DIR)/checker_exec.c

SHARED_SRCS	= \
$(COMM_DIR)/push.c \
$(COMM_DIR)/reverse_rotate.c \
$(COMM_DIR)/rotate.c \
$(COMM_DIR)/swap.c \
\
$(PS_DIR)/handle_errors.c \
$(PS_DIR)/stack_init.c \
$(PS_DIR)/stack_utils.c

# =========================
#     OBJECT FILES
# =========================

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(OBJS_DIR)/, $(BONUS_SRCS:.c=.o))
SHARED_OBJS	= $(addprefix $(OBJS_DIR)/, $(SHARED_SRCS:.c=.o))

# Progress tracking
TOTAL_SRCS	= $(words $(SRCS))
BONUS_TOTAL	= $(words $(BONUS_SRCS))
SHARED_TOTAL = $(words $(SHARED_SRCS))
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
	@echo "\033[38;5;22m ░       ░░░  ░░░░  ░░░      ░░░  ░░░░  ░░░      ░░░  ░░░░  ░░░      ░░░       ░░"
	@echo "\033[38;5;28m ▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒  ▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒"
	@echo "\033[38;5;34m ▓       ▓▓▓  ▓▓▓▓  ▓▓▓      ▓▓▓        ▓▓▓      ▓▓▓        ▓▓  ▓▓▓▓  ▓▓       ▓▓"
	@echo "\033[38;5;40m █  ████████  ████  ████████  ██  ████  ████████  ██   ██   ██        ██  ███████"
	@echo "\033[38;5;46m █  █████████      ████      ███  ████  ███      ███  ████  ██  ████  ██  ███████"
	@echo "\033[38;5;46m                                                                      by viceda-s $(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/$(COMM_DIR)
	@mkdir -p $(OBJS_DIR)/$(PS_DIR)
	@mkdir -p $(OBJS_DIR)/$(BONUS_DIR)

$(NAME): $(OBJS_DIR) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(BOLD)$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(eval IS_BONUS=$(filter bonus,$(MAKECMDGOALS)))
	@$(eval TARGET=$(if $(IS_BONUS),checker,push_swap))
	@$(eval TOTAL=$(if $(IS_BONUS),$(TOTAL_BONUS_FILES),$(TOTAL_SRCS)))
	@$(eval BONUS_COUNT=$(shell find $(OBJS_DIR)/$(BONUS_DIR) -name '*.o' 2>/dev/null | wc -l))
	@$(eval SHARED_COUNT=$(shell find $(OBJS_DIR)/srcs -name '*.o' 2>/dev/null | wc -l))
	@$(eval CURRENT=$(if $(IS_BONUS),$(shell echo $$(($(BONUS_COUNT) + $(SHARED_COUNT)))),$(shell find $(OBJS_DIR) -name '*.o' 2>/dev/null | wc -l)))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT) * 100 / $(TOTAL)))))
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

bonus: clean_bonus_objs $(BONUS)

clean_bonus_objs:
	@$(RM) -r $(OBJS_DIR)/$(BONUS_DIR) $(OBJS_DIR)/$(SRCS_DIR)

$(BONUS): $(OBJS_DIR) $(LIBFT) $(BONUS_OBJS) $(SHARED_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(SHARED_OBJS) $(LIBFT) -o $(BONUS)
	@echo "$(BOLD)$(GREEN)✓ $(BONUS) compiled successfully!$(RESET)"

clean:
	@printf "\n$(BOLD)$(RED)Cleaning:$(RESET)\n"
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
	@echo ""

re: fclean all

.PHONY: all clean fclean re bonus print_header
