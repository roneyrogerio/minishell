/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:08:37 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/10/22 17:29:37 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"
#include "lexer.h"

int	read_cmd(void)
{
	char	*line;
	int		multiline;
	char	*ptr;

	multiline = 1;
	ft_putstr_fd("$ ", 1);
	while (multiline)
	{
		g_lx.i = 0;
		get_next_line(0, &line);
		ptr = line;
		if ((line = ft_strjoin(line, "\n")) == NULL)
			g_errno = SH_MEMERR;
		free(ptr);
		if ((multiline = parser(line)) == -1 || !syntax())
			return (-1);
		free(line);
		g_lx.line = NULL;
		if (multiline)
			ft_putstr_fd("> ", 1);
	}
	return (1);
}

int	parser(char *line)
{
	t_token		*token;
	t_token		*last;

	if (line == NULL)
		return (-1);
	last = NULL;
	while ((token = lexer(line)))
	{
		last = token;
		tokens_add(&g_tokens, token);
	}
	if (g_errno != 0)
		return (-1);
	else if (last && last->name == NEWLINE &&
			(((last->prev && last->prev->name != PIPE) &&
			(last->prev && last->prev->name != NEWLINE)) ||
			(!last->prev)))
		return (0);
	return (1);
}

int	syntax(void)
{
	t_token	*token;

	token = g_tokens;
	while (token)
	{
		if ((token->name == SEMI || token->name == PIPE) &&
				(!token->prev || token->prev->name != LITERAL))
		{
			g_errno = SH_SYNERR;
			return (0);
		}
		token = token->next;
	}
	return (1);
}
