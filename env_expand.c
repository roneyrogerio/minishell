/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:07:09 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 00:20:52 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_expand_argv(int i)
{
	int	j;
	int	k;

	j = 0;
	while (g_sh.ast[i].argv[j] && (k = 0) == 0)
	{
		while (g_sh.ast[i].argv[j] && g_sh.ast[i].argv[j][k])
		{
			if (g_sh.ast[i].argv[j][k] != '$' && (++k))
				continue ;
			if (k && g_sh.ast[i].argv[j][k - 1] == -1 && (++k))
				env_expand_literal(i, j, k - 1);
			else if (env_name_len(i, j, k + 1) && !env_expand_real(i, j, k))
				return (0);
			else if (g_sh.ast[i].argv[j][k] && !env_name_len(i, j, k))
				k++;
			if (argv_rm_empty(i, j))
				k = 0;
		}
		j++;
	}
	return (1);
}

void	env_expand_literal(int i, int j, int k)
{
	k--;
	while (g_sh.ast && g_sh.ast[i].argv && g_sh.ast[i].argv[j][k])
	{
		g_sh.ast[i].argv[j][k] = g_sh.ast[i].argv[j][k + 1];
		k++;
	}
}

int		env_expand_real(int i, int j, int k)
{
	char	*env;
	int		left_len;
	int		middle_len;
	int		right_len;
	char	*new;

	if ((env = env_expand_value(i, j, k + 1)) == NULL)
		return (0);
	left_len = k;
	middle_len = env_middle_len(env);
	right_len = ft_strlen(&g_sh.ast[i].argv[j][k + 1 +
			env_name_len(i, j, k + 1)]);
	if ((new = shelloc(left_len + middle_len + right_len + 1)) == NULL)
		return (0);
	ft_memcpy(new, g_sh.ast[i].argv[j], left_len);
	ft_memcpy(new + left_len, env, middle_len);
	ft_memcpy(new + left_len + middle_len,
			&g_sh.ast[i].argv[j][k + 1 + env_name_len(i, j, k + 1)],
			right_len);
	if (g_sh.ast[i].argv[j][k + 1] == '?')
		free(env);
	free(g_sh.ast[i].argv[j]);
	g_sh.ast[i].argv[j] = new;
	return (1);
}

char	*env_expand_value(int i, int j, int k)
{
	char	*env;

	if (g_sh.ast[i].argv[j][k] != '?')
	{
		if (!(env = env_var(&g_sh.ast[i].argv[j][k], env_name_len(i, j, k))))
			env = "";
	}
	else
	{
		if ((env = ft_itoa(g_sh.status)) == NULL)
		{
			g_errno = SH_MEMERR;
			return (NULL);
		}
	}
	return (env);
}

int		argv_rm_empty(int i, int j)
{
	char	*ptr;

	if (g_sh.ast[i].argv[j][0] != '\0')
		return (0);
	ptr = g_sh.ast[i].argv[j];
	while (g_sh.ast[i].argv[j])
	{
		g_sh.ast[i].argv[j] = g_sh.ast[i].argv[j + 1];
		j++;
	}
	free(ptr);
	return (1);
}
