/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:02:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/26 12:41:10 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		int_export(int i)
{
	int		j;
	int		name_len;
	char	*find;

	j = 1;
	while (g_sh.ast[i].argv[j])
	{
		if (strchr(g_sh.ast[i].argv[j], '=') == NULL)
			set_env_exp(g_sh.ast[i].argv[j]);
		else
		{
			name_len = env_join_name_len(g_sh.ast[i].argv[j]);
			find = env_var(g_sh.ast[i].argv[j], name_len);
			if (find == NULL && !env_join_new(g_sh.ast[i].argv[j], 1))
				return (0);
			else if (!env_join_same(g_sh.ast[i].argv[j], 1))
				return (0);
		}
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

int		int_unset(int i)
{
	int	j;

	j = 1;
	while (g_sh.ast[i].argv[j])
	{
		unset_env(g_sh.ast[i].argv[j]);
		j++;
	}
	return (1);
}

void	unset_env(char *name)
{
	t_env_lst	*env;
	t_env_lst	*prev;
	char		*var;

	env = g_sh.env;
	var = NULL;
	prev = NULL;
	while (env)
	{
		var = env_start(env->content->value, name, ft_strlen(name));
		if (var != NULL)
		{
			if (prev)
				prev->next = env->next;
			else
				g_sh.env = env->next;
			free(env->content->value);
			free(env->content);
			free(env);
			break ;
		}
		prev = env;
		env = env->next;
	}
}
