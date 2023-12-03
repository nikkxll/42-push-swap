NAME = push_swap

CC = clang
CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = operations_a.c \
  operations_b.c \
  parser.c \
  main.c \
  one_stack_sort.c \
  two_stack_sort.c

OBJS = $(SRCS:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@echo "$(GREEN)!!! Library 'libft.a' created$(NC)"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)!!! Executable '$(NAME)' created$(NC)"
	@echo "$(GREEN)!!! Compilation completed successfully$(NC)"

$(LIBFT):
	@$(MAKE) -C libft/
	@$(MAKE) bonus -C libft/

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)!!! Cleaned object files$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)!!! Removed '$(NAME)'$(NC)"
	@echo "$(RED)!!! Cleaned everything$(NC)"

re: fclean all
	@echo "$(GREEN)!!! Everything recompiled$(NC)"

.PHONY: all clean fclean re