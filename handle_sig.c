/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:23:19 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 11:26:02 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sig(int sig)
{
	if (sig == SIGINT && (g_sh.status = 130))
	{
		ft_putchar_fd('\n', 1);
		if (!g_sh.ast)
			ft_putstr_fd("$ ", 1);
		sh_free();
	}
	else if (sig == SIGCHLD)
	{
		wait(NULL);
	}
	else if (sig == SIGQUIT && (g_sh.status = 131))
	{
		ft_putstr_fd("Quit\n", 1);
		if (!g_sh.ast)
			ft_putstr_fd("$ ", 1);
		kill_pids(SIGQUIT);
		sh_free();
	}
}
