/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:26:20 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 21:39:26 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtins(int i)
{
	if (ft_strcmp(g_sh.ast[i].argv[0], "echo") == 0 && int_echo(i))
		return (1);
	return (0);
}

int		int_echo(int i)
{
	int	newline;
	int	j;

	newline = 1;
	j = 1;
	if (g_sh.ast[i].argv[1] && ft_strcmp(g_sh.ast[i].argv[1], "-n") == 0)
	{
		newline = 0;
		j = 2;
	}
	while (g_sh.ast[i].argv[j])
	{
		ft_putstr_fd(g_sh.ast[i].argv[j], 1);
		if (g_sh.ast[i].argv[j + 1])
			ft_putchar_fd(' ', 1);
		j++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (1);
}

int		int_cd(int i)
{
	char	*path;

	path = g_sh.ast[i].argv[1];
	if (path == NULL)
	{
		if ((path = env_var("HOME", 4)) == NULL)
			path = ".";
	}
	else if (g_sh.ast[i].argv[2] != NULL && (g_errno = SH_MANYARG))
		return (0);
	if (chdir(path) == -1)
		return (0);
	return (1);
}
