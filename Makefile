NAME = push_swap
BONUS = checker

CC = clang
CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = ./libft/
SRCS_PATH = ./srcs/

LIBFT = $(LIBFT_DIR)/libft.a
SRCS_PS = push_swap_main.c
SRCS_ALL = operations.c operations_extra.c parser.c push_swap.c one_stack_sort.c \
  mini_sort.c support_array_creation.c sort.c sort_rotation_print.c \
  rotations_without_write.c finders.c utils.c push_swap_without_write.c
SRCS_CH = checker.c
HEADER = push_swap.h

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_PS)) $(addprefix $(SRCS_PATH), $(SRCS_ALL))
SRCS_BONUS = $(addprefix $(SRCS_PATH), $(SRCS_CH)) $(addprefix $(SRCS_PATH), $(SRCS_ALL))

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(HEADER)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✅ Compilation of '$(NAME)' completed successfully$(NC)"

$(BONUS): $(SRCS_BONUS) $(LIBFT) $(HEADER)
	@$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(BONUS)
	@echo "$(GREEN)✅ Compilation of '$(BONUS)' completed successfully$(NC)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

bonus: $(BONUS)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@rm -f $(NAME) $(BONUS)
	@echo "$(BLUE)🧹 Removed '$(NAME)'$(NC)"
	@make -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "$(GREEN)🚀 Everything recompiled$(NC)"

.PHONY: all clean fclean re