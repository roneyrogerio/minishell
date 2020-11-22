/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:46:08 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 10:51:07 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_pids(void)
{
	int	status;
	int	i;

	i = 0;
	while (g_sh.ast && i < g_sh.len)
	{
		if (g_sh.ast && g_sh.ast[i].pid > 0)
		{
			if (waitpid(g_sh.ast[i].pid, &status, 0) != -1)
			{
				g_sh.status = WEXITSTATUS(status);
			}
			if (g_sh.ast)
				g_sh.ast[i].pid = 0;
		}
		i++;
	}
}

void	kill_pids(int signal)
{
	int	i;

	i = 0;
	while (g_sh.ast && i < g_sh.len)
	{
		if (g_sh.ast && g_sh.ast[i].pid > 0)
		{
			kill(g_sh.ast[i].pid, signal);
			g_sh.ast[i].pid = 0;
		}
		i++;
	}
}
