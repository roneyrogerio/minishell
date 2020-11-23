/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:56:31 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/23 12:17:05 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run_cmd_exec_argv(int i)
{
	if (!env_expand_argv(i))
		return (0);
	else if (ft_strcmp(g_sh.ast[i].argv[0], "exit") == 0 &&
			(!i || (i && g_sh.ast[i - 1].end == 1)) &&
			(g_sh.ast[i].end == 1 || i == g_sh.len - 1) && !sh_exit_cmd(i))
		return (0);
	else if (ft_strcmp(g_sh.ast[i].argv[0], "cd") == 0 &&
			(!i || (i && g_sh.ast[i - 1].end == 1)) &&
			(g_sh.ast[i].end == 1 || i == g_sh.len - 1) && !int_cd(i))
		return (0);
	else if (ft_strcmp(g_sh.ast[i].argv[0], "export") == 0 &&
			(!i || (i && g_sh.ast[i - 1].end == 1)) &&
			(g_sh.ast[i].end == 1 || i == g_sh.len - 1) && !int_export(i))
		return (0);
	else if (ft_strcmp(g_sh.ast[i].argv[0], "unset") == 0 &&
			(!i || (i && g_sh.ast[i - 1].end == 1)) &&
			(g_sh.ast[i].end == 1 || i == g_sh.len - 1) && !int_unset(i))
		return (0);
	else if (ft_strcmp(g_sh.ast[i].argv[0], "exit") != 0 &&
			ft_strcmp(g_sh.ast[i].argv[0], "cd") != 0 &&
			ft_strcmp(g_sh.ast[i].argv[0], "export") != 0 &&
			ft_strcmp(g_sh.ast[i].argv[0], "unset") != 0 && !exec_fork(i))
		return (0);
	return (1);
}
