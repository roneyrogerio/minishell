/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:50:36 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/11 16:23:15 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ast_clear(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_sh.ast && i < g_sh.len)
	{
		j = 0;
		while (g_sh.ast[i].argv && g_sh.ast[i].argv[j])
		{
			free(g_sh.ast[i].argv[j]);
			j++;
		}
		free(g_sh.ast[i].argv);
		j = 0;
		while (g_sh.ast[i].env && g_sh.ast[i].env[j])
		{
			free(g_sh.ast[i].env[j]);
			j++;
		}
		free(g_sh.ast[i].env);
		i++;
	}
	free(g_sh.ast);
}
