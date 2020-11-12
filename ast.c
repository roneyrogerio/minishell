/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:07:26 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/11 15:36:38 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ast(t_token *tokens)
{
	int		i;

	g_sh.len = ast_len(tokens);
	if ((g_sh.ast = (t_ast *)shelloc(g_sh.len * sizeof(t_ast))) == NULL)
		return (0);
	i = 0;
	while (tokens && g_sh.len && !g_errno && !errno)
	{
		if (tokens->name == SEMI)
		{
			g_sh.ast[i].end = 1;
			tokens = tokens->next;
		}
		else if (tokens->name != NEWLINE && tokens->name != PIPE)
			ast_item(&tokens, i);
		else
			tokens = tokens->next;
		if (tokens && (tokens->name == LITERAL || tokens->name == ENV) &&
			(!tokens->prev || tokens->prev->name != ENV))
			i++;
	}
	if (g_errno != 0 || errno != 0)
		return (0);
	return (1);
}

void	ast_item(t_token **tokens, int i)
{
	if ((*tokens)->name == LITERAL ||
		(*tokens)->name == LESS ||
		(*tokens)->name == GREAT ||
		(*tokens)->name == DGREAT)
		ast_argv(tokens, i);
	else if ((*tokens)->name == ENV)
		ast_env(tokens, i);
}

void	ast_argv(t_token **tokens, int i)
{
	int	j;
	int	len;

	len = ast_literal_len(*tokens) + 1;
	if ((g_sh.ast[i].argv = (char **)shelloc(len * sizeof(char *))) == NULL)
		return ;
	g_sh.ast[i].argv[len - 1] = NULL;
	j = 0;
	while (*tokens && ((*tokens)->name == LITERAL ||
						(*tokens)->name == LESS ||
						(*tokens)->name == GREAT ||
						(*tokens)->name == DGREAT))
	{
		if ((*tokens)->name == LITERAL)
		{
			if ((g_sh.ast[i].argv[j] = sh_strdup((*tokens)->value)) == NULL)
				return ;
			j++;
		}
		else
			ast_redirect(tokens, i);
		*tokens = (*tokens)->next;
	}
}

void	ast_redirect(t_token **tokens, int i)
{
	char	*file;

	file = (*tokens)->next->value;
	if (g_sh.ast[i].fd_out > 2 &&
			((*tokens)->name == GREAT || (*tokens)->name == DGREAT))
		close(g_sh.ast[i].fd_out);
	else if (g_sh.ast[i].fd_in > 2 && (*tokens)->name == LESS)
		close(g_sh.ast[i].fd_in);
	if ((*tokens)->name == LESS)
		g_sh.ast[i].fd_in = open(file, O_RDONLY);
	else if ((*tokens)->name == GREAT)
	{
		g_sh.ast[i].fd_out = open(file, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR);
		write(g_sh.ast[i].fd_out, "", 0);
	}
	else if ((*tokens)->name == DGREAT)
	{
		g_sh.ast[i].fd_out = open(file, O_CREAT | O_WRONLY,
				S_IRUSR | S_IWUSR);
		write(g_sh.ast[i].fd_out, "", 0);
		g_sh.ast[i].append = 1;
	}
	*tokens = (*tokens)->next;
}

void	ast_env(t_token **tokens, int i)
{
	int	j;
	int	len;

	len = ast_env_len(*tokens) + 1;
	if (len == 1)
	{
		*tokens = (*tokens)->next;
		return ;
	}
	if ((g_sh.ast[i].env = (char **)shelloc(len * sizeof(char *))) == NULL)
		return ;
	g_sh.ast[i].env[len - 1] = NULL;
	j = 0;
	while (*tokens && (*tokens)->name == ENV)
	{
		if ((g_sh.ast[i].env[j] = sh_strdup((*tokens)->value)) == NULL)
			return ;
		*tokens = (*tokens)->next;
		j++;
	}
}
