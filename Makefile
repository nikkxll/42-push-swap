NAME = push_swap

CC = clang
CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = operations.c operations_extra.c parser.c main.c one_stack_sort.c \
  mini_sort.c support_array_creation.c sort.c sort_rotation_print.c \
  rotations_without_write.c finders.c utils.c

OBJS = $(SRCS:.c=.o)

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✅ Compilation completed successfully$(NC)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@rm -f $(NAME)
	@echo "$(BLUE)🧹 Removed '$(NAME)'$(NC)"
	@make -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "$(GREEN)🚀 Everything recompiled$(NC)"

.PHONY: all clean fclean re