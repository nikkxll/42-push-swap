NAME = libft.a
	
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = clang
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@ar -rcs ../$(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: .bonus

.bonus: $(OBJS_BONUS)
	@ar -rcs $(NAME) $(OBJS_BONUS)
	@ar -rcs ../$(NAME) $(OBJS_BONUS)
	@touch .bonus

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@$(RM) .bonus

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ../$(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus