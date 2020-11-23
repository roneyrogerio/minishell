/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:26:05 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/23 12:32:05 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_exit(int status)
{
	env_lst_clear();
	sh_free();
	ft_putstr_fd("exit\n", 1);
	exit(status);
}

int		sh_exit_cmd(int i)
{
	char	*status_ptr;
	int		status;

	status_ptr = g_sh.ast[i].argv[1];
	if (status_ptr && !ft_isnumber(status_ptr))
	{
		g_errno = SH_NOTNUM;
		return (0);
	}
	else if (status_ptr && g_sh.ast[i].argv[2])
	{
		g_errno = SH_MANYARG;
		return (0);
	}
	if (status_ptr)
		status = ft_atoi(status_ptr);
	else
		status = 0;
	sh_exit(status);
	return (status);
}
