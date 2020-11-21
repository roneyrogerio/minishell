/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:48:27 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/21 15:54:42 by rde-oliv         ###   ########.fr       */
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
		if (find == NULL)
		{
			if (!env_join_new(i, j))
				return (0);
		}
		else
		{
			if (!env_join_same(i, j))
				return (0);
		}
		j++;
	}
	return (1);
}

int		env_join_new(int i, int j)
{
	char	**new;
	int		len;
	int		k;

	len = ft_splitlen(g_sh.env);
	if ((new = (char **)shelloc((len + 2) * sizeof(char *))) == NULL)
		return (0);
	k = 0;
	while (g_sh.env[k])
	{
		new[k] = g_sh.env[k];
		k++;
	}
	if ((new[len] = sh_strdup(g_sh.ast[i].env[j])) == NULL)
	{
		free(new);
		return (0);
	}
	free(g_sh.env);
	g_sh.env = new;
	return (1);
}

int		env_join_same(int i, int j)
{
	char	*new;
	int		pos;

	pos = env_join_same_pos(i, j);
	if ((new = sh_strdup(g_sh.ast[i].env[j])) == NULL)
		return (0);
	free(g_sh.env[pos]);
	g_sh.env[pos] = new;
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

int		env_join_same_pos(int i, int j)
{
	int		len;
	int		pos;
	int		k;

	len = env_join_name_len(g_sh.ast[i].env[j]);
	pos = 0;
	k = 0;
	while (g_sh.env[k])
	{
		if (env_start(g_sh.env[k], g_sh.ast[i].env[j], len) != NULL)
			break ;
		k++;
	}
	return (k);
}
