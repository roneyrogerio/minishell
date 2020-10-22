/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:50:03 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/10/22 09:08:24 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

t_token	*lexer(char *line)
{
	t_token	*token;

	g_lx.line = line;
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
		if (g_lx.line[g_lx.i] == '\'' && lx_isqte())
		{
			if (g_lx.qte && !value)
				value = ft_strdup("");
			g_lx.qte = g_lx.qte ? 0 : 1;
		}
		else if (g_lx.line[g_lx.i] == '"' && lx_isqte())
		{
			if (g_lx.dqte && !value)
				value = ft_strdup("");
			g_lx.dqte = g_lx.dqte ? 0 : 1;
		}
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

	if (*value == NULL)
	{
		if ((*value = ft_substr(g_lx.line + g_lx.i, 0, 1)) == NULL)
			g_errno = SH_MEMERR;
	}
	else
	{
		ptr = *value;
		new = ft_substr(g_lx.line + g_lx.i, 0, 1);
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
