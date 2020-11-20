/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 10:49:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/19 20:43:51 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_var(char *name, int len)
{
	char	*var;
	int		i;

	var = NULL;
	i = 0;
	while (g_sh.env[i])
	{
		var = env_start(g_sh.env[i], name, len);
		if (var != NULL)
			break ;
		i++;
	}
	return (var);
}
