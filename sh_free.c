/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:53:41 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 10:50:10 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_free(void)
{
	kill_pids(SIGKILL);
	sh_free_lx();
	sh_free_ast();
	errno = 0;
	g_errno = 0;
}

void	sh_free_lx(void)
{
	tokens_clear();
	free(g_lx.line);
	free(g_lx.cache);
	g_lx.line = NULL;
	g_tokens = NULL;
	g_lx.cache = NULL;
	g_lx.qte = 0;
	g_lx.dqte = 0;
	g_lx.env = 0;
}

void	sh_free_ast(void)
{
	ast_close_redirections();
	ast_clear();
	g_sh.ast = NULL;
}
