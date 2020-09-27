NAME      = minishell
CC        = clang
SRCS      = minishell.c get_next_line.c
OBJS     := $(SRCS:.c=.o)
HEADER    = minishell.h
CFLAGS    = -Werror -Wextra -Wall
LIBFT     = libft
LIBFT_MOD = libft/Makefile

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/$(LIBFT).a -o $(NAME)

.FORCE:
$(LIBFT): .FORCE $(LIBFT_MOD)
	make -C $(LIBFT)

$(LIBFT_MOD):
	git submodule update --init

%.o: %.c minishell.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
