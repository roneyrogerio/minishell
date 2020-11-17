/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:46:08 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/13 20:21:09 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_pids(void)
{
	int	i;

	i = 0;
	while (g_sh.ast && i < g_sh.len)
	{
		if (g_sh.ast && g_sh.ast[i].pid > 0)
		{
			waitpid(g_sh.ast[i].pid, NULL, 0);
			if (g_sh.ast)
				g_sh.ast[i].pid = 0;
		}
		i++;
	}
}

void	kill_pids(void)
{
	int	i;

	i = 0;
	while (g_sh.ast && i < g_sh.len)
	{
		if (g_sh.ast && g_sh.ast[i].pid > 0)
		{
			kill(g_sh.ast[i].pid, SIGKILL);
			g_sh.ast[i].pid = 0;
		}
		i++;
	}
}
