/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:48:27 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/21 23:17:38 by rde-oliv         ###   ########.fr       */
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
		if (find == NULL && !env_join_new(i, j))
			return (0);
		else if (!env_join_same(i, j))
			return (0);
		j++;
	}
	return (1);
}

int		env_join_new(int i, int j)
{
	t_env_lst	*item;
	t_env		*content;

	item = NULL;
	if ((content = malloc(sizeof(t_env))) == NULL ||
		(item = ft_lstnew(content)) == NULL ||
		(content->value = ft_strdup(g_sh.ast[i].env[j])) == NULL)
	{
		g_errno = SH_MEMERR;
		free(content);
		free(item);
		return (0);
	}
	content->exp = 0;
	ft_lstadd_back((void **)&g_sh.env, item);
	return (1);
}

int		env_join_same(int i, int j)
{
	t_env_lst	*env;
	char		*new;
	int			len;

	env = g_sh.env;
	len = env_join_name_len(g_sh.ast[i].env[j]);
	while (env)
	{
		if (env_start(env->content->value, g_sh.ast[i].env[j], len) != NULL)
		{
			if ((new = sh_strdup(g_sh.ast[i].env[j])) == NULL)
				return (0);
			free(env->content->value);
			env->content->value = new;
			break ;
		}
		env = env->next;
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