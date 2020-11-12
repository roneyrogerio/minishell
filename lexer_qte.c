/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_qte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:39:13 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/09 14:28:01 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lx_qte(int qte, char **value)
{
	if (g_lx.qte && !*value)
		*value = ft_strdup("");
	if (qte == 1)
		g_lx.qte = 0;
	else
		g_lx.qte = 1;
}

void	lx_dqte(int dqte, char **value)
{
	if (g_lx.dqte && !*value)
		*value = ft_strdup("");
	if (dqte == 1)
		g_lx.dqte = 0;
	else
		g_lx.dqte = 1;
}
