NAME      = minishell
CC        = clang
SRCS      = minishell.c \
			get_next_line.c \
			sh_error.c \
			read_cmd.c \
			lexer.c \
			lexer_utils.c \
			lexer_qte.c \
			tokens.c \
			tokens_utils.c \
			minishell_utils.c \
			ast.c \
			ast_utils.c \
			ast_clear.c \
			env.c \
			env_utils.c \
			run_cmd.c \
			run_cmd_utils.c \
			run_error.c \
			find_path.c \
			env_expand.c \
			env_expand_utils.c \
			env_expand_set.c \
			env_expand_set_utils.c \
			env_join.c \
			handle_sig.c \
			pids.c \
			sh_free.c \
			sh_exit.c

OBJS     := $(SRCS:.c=.o)
HEADER    = minishell.h
CFLAGS    = -Werror -Wextra -Wall -g
LIBFT     = libft
LIBFT_MOD = libft/Makefile

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/$(LIBFT).a -o $(NAME)

.FORCE:
$(LIBFT): .FORCE $(LIBFT_MOD)
	make bonus -C $(LIBFT)

$(LIBFT_MOD):
	git submodule update --init

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
