/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 10:49:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 16:04:39 by rde-oliv         ###   ########.fr       */
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

void	env_lst_clear(void)
{
	t_env_lst	*ptr;

	while (g_sh.env)
	{
		free(g_sh.env->content->value);
		free(g_sh.env->content);
		ptr = g_sh.env;
		g_sh.env = g_sh.env->next;
		free(ptr);
	}
}

char	**env_get(void)
{
	t_env_lst	*env_lst;
	char		**env;
	int			len;
	int			i;

	len = env_len();
	if ((env = (char **)shelloc((len + 1) * sizeof(char *))) == NULL)
		return (NULL);
	env_lst = g_sh.env;
	i = 0;
	while (env_lst)
	{
		if (env_lst->content->exp == 1)
		{
			if ((env[i] = sh_strdup(env_lst->content->value)) == NULL)
			{
				ft_splitclear(env);
				env = NULL;
				break ;
			}
			i++;
		}
		env_lst = env_lst->next;
	}
	return (env);
}
