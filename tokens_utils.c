/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:51:40 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/09 14:59:07 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokens_print(void)
{
	t_token	*tokens;

	tokens = g_tokens;
	while (tokens)
	{
		ft_putchar_fd('(', 1);
		ft_putstr_fd(token_name(tokens->name), 1);
		if (tokens->name == LITERAL || tokens->name == ENV)
			ft_putstr_fd(tokens->value, 1);
		ft_putchar_fd(')', 1);
		tokens = tokens->next;
	}
	ft_putchar_fd('\n', 1);
}

char	*token_name(int name)
{
	if (name == NEWLINE)
		return ("NEWLINE");
	else if (name == LESS)
		return ("LESS");
	else if (name == GREAT)
		return ("GREAT");
	else if (name == DGREAT)
		return ("DGREAT");
	else if (name == PIPE)
		return ("PIPE");
	else if (name == SEMI)
		return ("SEMI");
	else if (name == LITERAL)
		return ("LITERAL: ");
	else if (name == ENV)
		return ("ENV: ");
	else
		return ("");
}
