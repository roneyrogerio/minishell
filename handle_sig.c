/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:23:19 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 11:11:06 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sig(int sig)
{
	if (sig == 2)
	{
		ft_putchar_fd('\n', 1);
		if (!g_sh.ast)
			ft_putstr_fd("$ ", 1);
		sh_free();
	}
	else if (sig == 17)
	{
		wait(NULL);
	}
	else if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit\n", 1);
		if (!g_sh.ast)
			ft_putstr_fd("$ ", 1);
		kill_pids(SIGQUIT);
		sh_free();
	}
}
