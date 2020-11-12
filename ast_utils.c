/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:29:14 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/11 13:54:54 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ast_len(t_token *tokens)
{
	int		len;

	len = 0;
	while (tokens)
	{
		if (tokens->name == PIPE ||
			tokens->name == SEMI ||
			(tokens->name == NEWLINE && tokens->next == NULL &&
			tokens->prev != NULL && tokens->prev->name != SEMI))
			len++;
		tokens = tokens->next;
	}
	return (len);
}

int		ast_literal_len(t_token *tokens)
{
	int		len;

	len = 0;
	while (tokens)
	{
		if (tokens->name == LITERAL)
			len++;
		else if (tokens->name == LESS ||
				tokens->name == GREAT ||
				tokens->name == DGREAT)
			len--;
		else if (tokens->name == PIPE ||
				tokens->name == SEMI)
			break ;
		tokens = tokens->next;
	}
	return (len);
}

int		ast_env_len(t_token *tokens)
{
	int		len;

	len = 0;
	while (tokens)
	{
		if (tokens->name == LITERAL || tokens->name == PIPE)
			return (0);
		else if (tokens->name == SEMI)
			break ;
		tokens = tokens->next;
		len++;
	}
	return (len);
}

void	ast_print(void)
{
	int	i;
	int	j;

	i = 0;
	ft_putstr_fd("\n--------------------------------\n", 1);
	while (i < g_sh.len)
	{
		j = 0;
		ft_putstr_fd("ARGV: ", 1);
		while (g_sh.ast[i].argv && g_sh.ast[i].argv[j])
		{
			ft_putstr_fd(g_sh.ast[i].argv[j], 1);
			ft_putstr_fd(",", 1);
			j++;
		}
		ft_putstr_fd("\n", 1);
		ast_print_env(i);
		if (g_sh.ast[i].end)
			ft_putstr_fd("END\n", 1);
		ft_putstr_fd("--------------------------------\n", 1);
		i++;
	}
}

void	ast_print_env(int i)
{
	int	j;

	j = 0;
	ft_putstr_fd("ENV: ", 1);
	while (g_sh.ast[i].env && g_sh.ast[i].env[j])
	{
		ft_putstr_fd(g_sh.ast[i].env[j], 1);
		ft_putstr_fd(",", 1);
		j++;
	}
	ft_putstr_fd("\n", 1);
}
