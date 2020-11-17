/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:27:46 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/15 12:00:43 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_error(void)
{
	ft_putstr_fd("minishell: ", 2);
	if (errno != 0)
		ft_putstr_fd(strerror(errno), 2);
	else
		ft_putstr_fd(sh_strerror(g_errno), 2);
	ft_putchar_fd('\n', 2);
	g_errno = 0;
}

char	*sh_strerror(int errnum)
{
	if (errnum == SH_MEMERR)
		return ("error while allocating memory.");
	if (errnum == SH_SYNERR)
		return ("syntax error");
	if (errnum == SH_PATHERR)
		return ("error while looking for the bin path.");
	return (NULL);
}
