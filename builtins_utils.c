/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:02:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/23 01:41:28 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		int_export(int i)
{
	int	j;

	j = 1;
	while (g_sh.ast[i].argv[j])
	{
		set_env_exp(g_sh.ast[i].argv[j]);
		j++;
	}
	return (1);
}

void	set_env_exp(char *name)
{
	t_env_lst	*env;
	char		*var;

	env = g_sh.env;
	var = NULL;
	while (env)
	{
		var = env_start(env->content->value, name, ft_strlen(name));
		if (var != NULL)
		{
			env->content->exp = 1;
			break ;
		}
		env = env->next;
	}
}
