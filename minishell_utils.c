/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:49:40 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/08 17:22:48 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*shelloc(int size)
{
	void	*ret;

	if ((ret = ft_calloc(1, size)) == NULL)
		g_errno = SH_MEMERR;
	return (ret);
}

char	*sh_strdup(char *str)
{
	char	*ret;

	if ((ret = ft_strdup(str)) == NULL)
		g_errno = SH_MEMERR;
	return (ret);
}
