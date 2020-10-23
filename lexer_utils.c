/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:36:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/10/23 12:34:43 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "tokens.h"

int		lx_isspecial(void)
{
	int	escape;

	escape = 0;
	if (g_lx.i > 0 && g_lx.line[g_lx.i - 1] == '\\')
		escape = 1;
	if (!g_lx.qte && !g_lx.dqte && !escape &&
			(g_lx.line[g_lx.i] == NEWLINE ||
			g_lx.line[g_lx.i] == LESS ||
			g_lx.line[g_lx.i] == GREAT ||
			g_lx.line[g_lx.i] == PIPE ||
			g_lx.line[g_lx.i] == SEMI))
		return (1);
	return (0);
}

int		lx_isliteral(void)
{
	int	escape;

	escape = 0;
	if (g_lx.i > 0 && g_lx.line[g_lx.i - 1] == '\\')
		escape = 1;
	if ((g_lx.qte || g_lx.dqte) ||
		(!lx_isspecial() && g_lx.line[g_lx.i] != ' '))
		return (1);
	else if (!g_lx.qte && !g_lx.dqte && escape && g_lx.line[g_lx.i] == ' ')
		return (1);
	return (0);
}

int		lx_isqte(void)
{
	int	escape;

	escape = 0;
	if (g_lx.i > 0 && g_lx.line[g_lx.i - 1] == '\\')
		escape = 1;
	if (g_lx.line[g_lx.i] == '\'' && !escape && !g_lx.dqte)
		return (1);
	else if (g_lx.line[g_lx.i] == '"' && !escape && !g_lx.qte)
		return (1);
	return (0);
}

void	lx_cachejoin(char *value)
{
	char	*ptr;

	if (!g_lx.cache)
		g_lx.cache = value;
	else if (value)
	{
		ptr = g_lx.cache;
		if ((g_lx.cache = ft_strjoin(g_lx.cache, value)) == NULL)
			g_errno = SH_MEMERR;
		free(value);
		free(ptr);
	}
}

int		lx_islexeme(void)
{
	int	escape;

	escape = 0;
	if (g_lx.i > 0 && g_lx.line[g_lx.i - 1] == '\\')
		escape = 1;
	if (!g_lx.qte && !g_lx.dqte && g_lx.line[g_lx.i] == '\\' &&
			g_lx.line[g_lx.i + 1] != -1)
		return (0);
	else if (!g_lx.qte && g_lx.dqte && g_lx.line[g_lx.i] == '\\' &&
			g_lx.line[g_lx.i + 1] == '\n')
		return (0);
	else if (!g_lx.qte && g_lx.dqte && g_lx.line[g_lx.i] == '\\' &&
			(g_lx.line[g_lx.i + 1] == '\'' || g_lx.line[g_lx.i + 1] == '"'))
		return (0);
	else if (!g_lx.qte && escape && g_lx.line[g_lx.i] == '\n')
		return (0);
	return (1);
}
