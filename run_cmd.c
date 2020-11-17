/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:00:10 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/17 17:16:41 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run_cmd(void)
{
	int	i;

	i = 0;
	while (g_sh.ast && i < g_sh.len)
	{
		if (g_sh.ast && g_sh.ast[i].argv == NULL && g_sh.ast[i].env == NULL)
		{
			if (g_sh.ast && g_sh.ast[i].fd_in)
				close(g_sh.ast[i].fd_in);
			if (g_sh.ast && g_sh.ast[i].fd_out)
				close(g_sh.ast[i].fd_out);
		}
		else if (g_sh.ast && g_sh.ast[i].argv)
		{
			if (!exec_fork(i))
				return (-1);
		}
		if (g_sh.ast && (g_sh.ast[i].end || i == g_sh.len - 1))
			wait_pids();
		i++;
	}
	return (1);
}

int		exec_fork(int i)
{
	if ((g_sh.ast[i].path = find_path(g_sh.ast[i].argv[0])) == NULL)
		return (0);
	if (g_sh.ast && g_sh.ast[i].end == 0 && i + 1 < g_sh.len &&
			pipe(g_sh.ast[i].pfd) == -1)
		return (0);
	if (g_sh.ast && g_sh.ast[i].path[0] && (g_sh.ast[i].pid = fork()) == 0)
	{
		signal(SIGINT, NULL);
		signal(SIGCHLD, NULL);
		pipeline(i);
		redirection(i);
		execve(g_sh.ast[i].path, g_sh.ast[i].argv, NULL);
		exit(EXIT_SUCCESS);
	}
	else if (g_sh.ast && g_sh.ast[i].pid == -1)
		return (0);
	if (i && g_sh.ast[i - 1].pfd[0] > 0)
	{
		close(g_sh.ast[i - 1].pfd[0]);
		close(g_sh.ast[i - 1].pfd[1]);
	}
	return (1);
}

void	pipeline(int i)
{
	if (g_sh.ast && g_sh.ast[i].end == 0 && i + 1 < g_sh.len)
	{
		dup2(g_sh.ast[i].pfd[1], 1);
		close(g_sh.ast[i].pfd[0]);
		close(g_sh.ast[i].pfd[1]);
	}
	if (i && g_sh.ast && g_sh.ast[i - 1].pfd[0] > 0)
	{
		dup2(g_sh.ast[i - 1].pfd[0], 0);
		close(g_sh.ast[i - 1].pfd[0]);
		close(g_sh.ast[i - 1].pfd[1]);
	}
}

void	redirection(int i)
{
	if (g_sh.ast[i].fd_out > 0)
		dup2(g_sh.ast[i].fd_out, 1);
	if (g_sh.ast[i].fd_in > 0)
		dup2(g_sh.ast[i].fd_in, 0);
}
