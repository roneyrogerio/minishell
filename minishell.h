/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:09:46 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/26 01:50:38 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <limits.h>
# include "tokens.h"
# include "lexer.h"
# include "ast.h"
# include "env.h"
# include "run_cmd.h"
# include "env_expand.h"
# include "env_expand_set.h"
# include "env_join.h"
# include "find_path.h"
# include "pids.h"
# include "builtins.h"
# include "libft/libft.h"

typedef struct	s_sh
{
	t_ast		*ast;
	int			len;
	t_env_lst	*env;
	char		*name;
	int			status;
	int			after_cmd;
}				t_sh;

t_sh			g_sh;
int				g_errno;
int				read_cmd(void);
int				parser(char *line);
int				syntax(void);
void			sh_error(void);
char			*sh_strerror(int errnum);
void			tokens_print(void);
char			*token_name(int name);
void			*shelloc(int size);
char			*sh_strdup(char *str);
char			*sh_name(char *path);
void			sh_free(void);
void			sh_free_lx(void);
void			sh_free_ast(void);
void			handle_sig(int sig);
void			sh_exit(int status);
int				sh_exit_cmd(int i);

/*
** SH errors
*/
# define SH_MEMERR 1
# define SH_SYNERR 2
# define SH_PATHERR 3
# define SH_ENVCERR 4
# define SH_MANYARG 5
# define SH_NOTNUM 6

#endif
