/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:26:20 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 20:46:24 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		int_cd(int i)
{
	char	*path;

	path = g_sh.ast[i].argv[1];
	if (path == NULL)
	{
		if ((path = env_var("HOME", 4)) == NULL)
			path = "/";
	}
	else if (g_sh.ast[i].argv[2] != NULL && (g_errno = SH_MANYARG))
		return (0);
	if (chdir(path) == -1)
		return (0);
	return (1);
}
