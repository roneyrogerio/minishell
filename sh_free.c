/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:53:41 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/10/22 17:50:24 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_free(void)
{
	tokens_clear();
	free(g_lx.line);
	free(g_lx.cache);
	g_lx.line = NULL;
	g_tokens = NULL;
	g_lx.cache = NULL;
	g_lx.qte = 0;
	g_lx.dqte = 0;
}
