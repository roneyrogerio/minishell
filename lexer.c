/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:50:03 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/09 14:45:30 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

t_token	*lexer(char *line)
{
	t_token	*token;

	while (line && line[g_lx.i])
	{
		if (lx_isspecial())
		{
			token = lx_special();
			g_lx.i++;
			return (token);
		}
		else if (lx_isliteral())
		{
			token = lx_literal();
			return (token);
		}
		g_lx.i++;
	}
	return (NULL);
}

t_token	*lx_literal(void)
{
	char	*value;
	t_token	*token;

	g_lx.env = 0;
	value = lexeme();
	if ((g_lx.qte || g_lx.dqte) && !g_lx.cache)
		g_lx.cache = value;
	else if ((g_lx.qte || g_lx.dqte) && g_lx.cache)
		lx_cachejoin(value);
	else if (!g_lx.qte && !g_lx.dqte && !g_lx.cache && value)
	{
		if ((token = token_new(LITERAL, value)) == NULL)
			free(value);
		return (token);
	}
	else if (!g_lx.qte && !g_lx.dqte && g_lx.cache)
	{
		lx_cachejoin(value);
		if ((token = token_new(LITERAL, g_lx.cache)) == NULL)
			free(g_lx.cache);
		g_lx.cache = NULL;
		return (token);
	}
	return (NULL);
}

char	*lexeme(void)
{
	char			*value;

	value = NULL;
	while (lx_isliteral() && g_lx.line && g_lx.line[g_lx.i])
	{
		if (!g_lx.qte && g_lx.line[g_lx.i] == '\\' &&
				g_lx.line[g_lx.i + 1] == '\\')
			g_lx.line[g_lx.i + 1] = -1;
		if (!g_lx.qte && !g_lx.dqte && g_lx.line[g_lx.i] == '=')
			g_lx.env = 1;
		if (g_lx.line[g_lx.i] == '\'' && lx_isqte())
			lx_qte(g_lx.qte, &value);
		else if (g_lx.line[g_lx.i] == '"' && lx_isqte())
			lx_dqte(g_lx.dqte, &value);
		else if (g_lx.line[g_lx.i] != -1 && lx_islexeme())
			lexeme_join(&value);
		g_lx.i++;
	}
	return (value);
}

void	lexeme_join(char **value)
{
	char	*ptr;
	char	*new;

	if ((new = ft_substr(g_lx.line + g_lx.i, 0, 1)) == NULL)
		g_errno = SH_MEMERR;
	if (g_lx.line[g_lx.i] == '$' && g_lx.qte)
	{
		ptr = new;
		if ((new = ft_strjoin(" ", new)) == NULL)
			g_errno = SH_MEMERR;
		else
			new[0] = -1;
		free(ptr);
	}
	if (*value == NULL)
		*value = new;
	else
	{
		ptr = *value;
		*value = ft_strjoin(*value, new);
		if (new == NULL || *value == NULL)
			g_errno = SH_MEMERR;
		free(ptr);
		free(new);
	}
}

t_token	*lx_special(void)
{
	if (g_lx.line[g_lx.i] == '>' && g_lx.line[g_lx.i + 1] == '>')
	{
		g_lx.i++;
		return (token_new(DGREAT, NULL));
	}
	return (token_new(g_lx.line[g_lx.i], NULL));
}
