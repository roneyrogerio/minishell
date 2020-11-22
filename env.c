/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 10:49:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/21 23:03:54 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_var(char *name, int len)
{
	t_env_lst	*env;
	char		*var;

	env = g_sh.env;
	var = NULL;
	while (env)
	{
		var = env_start(env->content->value, name, len);
		if (var != NULL)
			break ;
		env = env->next;
	}
	return (var);
}
