/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:26:05 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 14:22:09 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_exit(int msg)
{
	env_lst_clear();
	sh_free();
	if (msg)
		ft_putstr_fd("exit\n", 1);
	exit(EXIT_SUCCESS);
}

int		is_exit(int i)
{
	if (ft_strcmp(g_sh.ast[i].argv[0], "exit") != 0)
		return (0);
	if (i && (g_sh.ast[i - 1].end == 0))
		return (0);
	return (1);
}

int		is_exitp(int i)
{
	if (ft_strcmp(g_sh.ast[i].argv[0], "exit") != 0)
		return (0);
	return (1);
}
