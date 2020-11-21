/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:07:09 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/21 16:29:32 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_expand_set(int i)
{
	int	j;
	int	k;

	j = 0;
	while (g_sh.ast[i].env[j] && (k = 0) == 0)
	{
		while (g_sh.ast[i].env[j] && g_sh.ast[i].env[j][k])
		{
			if (g_sh.ast[i].env[j][k] != '$' && (++k))
				continue ;
			if (k && g_sh.ast[i].env[j][k - 1] == -1 && (++k))
				expand_set_literal(i, j, k - 1);
			else if (env_set_name_len(i, j, k + 1) && !expand_set_real(i, j, k))
				return (0);
			else if (!env_set_name_len(i, j, k + 1))
				k++;
		}
		j++;
	}
	return (1);
}

void	expand_set_literal(int i, int j, int k)
{
	k--;
	while (g_sh.ast && g_sh.ast[i].env && g_sh.ast[i].env[j][k])
	{
		g_sh.ast[i].env[j][k] = g_sh.ast[i].env[j][k + 1];
		k++;
	}
}

int		expand_set_real(int i, int j, int k)
{
	char	*env;
	int		left_len;
	int		middle_len;
	int		right_len;
	char	*new;

	if ((env = expand_set_value(i, j, k + 1)) == NULL)
		return (0);
	left_len = k;
	middle_len = set_middle_len(env);
	right_len = ft_strlen(&g_sh.ast[i].env[j][k + 1 +
			env_set_name_len(i, j, k + 1)]);
	if ((new = shelloc(left_len + middle_len + right_len + 1)) == NULL)
		return (0);
	ft_memcpy(new, g_sh.ast[i].env[j], left_len);
	ft_memcpy(new + left_len, env, middle_len);
	ft_memcpy(new + left_len + middle_len,
			&g_sh.ast[i].env[j][k + 1 + env_set_name_len(i, j, k + 1)],
			right_len);
	if (g_sh.ast[i].env[j][k + 1] == '?')
		free(env);
	free(g_sh.ast[i].env[j]);
	g_sh.ast[i].env[j] = new;
	return (1);
}

char	*expand_set_value(int i, int j, int k)
{
	char	*env;

	if (g_sh.ast[i].env[j][k] != '?')
	{
		if (!(env = env_var(&g_sh.ast[i].env[j][k], env_set_name_len(i, j, k))))
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
