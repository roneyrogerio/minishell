/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:50:36 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 16:17:02 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ast_clear(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_sh.ast && i < g_sh.len && !(j = 0))
	{
		while (g_sh.ast && g_sh.ast[i].argv && g_sh.ast[i].argv[j])
		{
			free(g_sh.ast[i].argv[j]);
			j++;
		}
		free(g_sh.ast[i].argv);
		j = 0;
		while (g_sh.ast && g_sh.ast[i].env && g_sh.ast[i].env[j])
		{
			free(g_sh.ast[i].env[j]);
			j++;
		}
		free(g_sh.ast[i].env);
		ft_splitclear(g_sh.ast[i].g_env);
		if (g_sh.ast[i].path && g_sh.ast[i].path[0] != '\0')
			free(g_sh.ast[i].path);
		i++;
	}
	free(g_sh.ast);
}

void	ast_close_redirections(void)
{
	int	i;

	i = 0;
	while (g_sh.ast && i < g_sh.len)
	{
		if (g_sh.ast && g_sh.ast[i].fd_in)
			close(g_sh.ast[i].fd_in);
		if (g_sh.ast && g_sh.ast[i].fd_out)
			close(g_sh.ast[i].fd_out);
		i++;
	}
}
