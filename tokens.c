/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:25:09 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/10/22 08:56:37 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokens.h"

t_token	*token_new(int name, char *value)
{
	t_token	*token;

	if ((token = (t_token *)ft_calloc(1, sizeof(t_token))) == NULL)
	{
		g_errno = SH_MEMERR;
		return (NULL);
	}
	token->name = name;
	token->value = value;
	return (token);
}

void	tokens_add(t_token **tokens, t_token *token)
{
	t_token	*last;

	if (!tokens || !token)
		return ;
	if (!*tokens)
	{
		*tokens = token;
		return ;
	}
	last = token_last(*tokens);
	token->prev = last;
	last->next = token;
}

t_token	*token_last(t_token *token)
{
	while (token && token->next)
		token = token->next;
	return (token);
}

void	tokens_clear(void)
{
	t_token	*ptr;

	while (g_tokens)
	{
		free(g_tokens->value);
		ptr = g_tokens;
		g_tokens = g_tokens->next;
		free(ptr);
	}
}
