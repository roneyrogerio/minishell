/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:48:27 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/26 12:22:00 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_join(int i)
{
	int		j;
	int		name_len;
	char	*find;

	j = 0;
	while (g_sh.ast[i].env[j])
	{
		name_len = env_join_name_len(g_sh.ast[i].env[j]);
		find = env_var(g_sh.ast[i].env[j], name_len);
		if (find == NULL && !env_join_new(g_sh.ast[i].env[j], 0))
			return (0);
		else if (!env_join_same(g_sh.ast[i].env[j], -1))
			return (0);
		j++;
	}
	return (1);
}

int		env_join_new(char *env, int exp)
{
	t_env_lst	*item;
	t_env		*content;

	item = NULL;
	if ((content = malloc(sizeof(t_env))) == NULL ||
		(item = ft_lstnew(content)) == NULL ||
		(content->value = ft_strdup(env)) == NULL)
	{
		g_errno = SH_MEMERR;
		free(content);
		free(item);
		return (0);
	}
	content->exp = exp;
	ft_lstadd_back((void **)&g_sh.env, item);
	return (1);
}

int		env_join_same(char *env, int exp)
{
	t_env_lst	*envs;
	char		*new;
	int			len;

	envs = g_sh.env;
	len = env_join_name_len(env);
	while (envs)
	{
		if (env_start(envs->content->value, env, len) != NULL)
		{
			if ((new = sh_strdup(env)) == NULL)
				return (0);
			free(envs->content->value);
			envs->content->value = new;
			if (exp >= 0)
				envs->content->exp = exp;
			break ;
		}
		envs = envs->next;
	}
	return (1);
}

int		env_join_name_len(char *str)
{
	int	i;
	int len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		len++;
		i++;
	}
	return (len);
}
