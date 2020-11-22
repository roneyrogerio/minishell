/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:42:29 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 15:52:06 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef struct	s_ast
{
	char	**argv;
	char	**env;
	char	**g_env;
	char	*path;
	int		fd_in;
	int		fd_out;
	int		pid;
	int		pfd[2];
	int		end;
}				t_ast;

int				ast(t_token *tokens);
void			ast_item(t_token **tokens, int i);
void			ast_argv(t_token **tokens, int i);
void			ast_redirect(t_token **tokens, int i);
void			ast_env(t_token **tokens, int i);
int				ast_len(t_token *tokens);
int				ast_literal_len(t_token *tokens);
int				ast_env_len(t_token *tokens);
void			ast_print(void);
void			ast_print_env(int i);
void			ast_clear(void);
void			ast_close_redirections(void);

#endif
