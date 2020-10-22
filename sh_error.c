/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:27:46 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/10/22 08:48:39 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_error(void)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(sh_strerror(g_errno), 2);
	ft_putchar_fd('\n', 2);
	g_errno = 0;
	sh_free();
}

char	*sh_strerror(int errnum)
{
	if (errnum == SH_MEMERR)
		return ("error while allocating memory.");
	if (errnum == SH_SYNERR)
		return ("syntax error");
	return (NULL);
}
