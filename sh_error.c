/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:27:46 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/20 19:11:30 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_error(void)
{
	ft_putstr_fd(g_sh.name, 2);
	ft_putstr_fd(": ", 2);
	if (errno != 0)
		ft_putstr_fd(strerror(errno), 2);
	else
	{
		ft_putstr_fd(sh_strerror(g_errno), 2);
		g_sh.status = 2;
	}
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
	if (errnum == SH_ENVCERR)
		return ("error while cloning env vars.");
	return (NULL);
}
