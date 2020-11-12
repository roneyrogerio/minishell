/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:09:46 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/11 12:57:44 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "tokens.h"
# include "lexer.h"
# include "ast.h"
# include "env.h"
# include "libft/libft.h"

typedef struct	s_sh
{
	t_ast	*ast;
	int		len;
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
void			sh_free(void);
void			sh_free_lx(void);
void			sh_free_ast(void);

/*
** SH errors
*/
# define SH_MEMERR 1
# define SH_SYNERR 2

#endif
