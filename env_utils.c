/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:43:26 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/19 22:29:19 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_env(char *lexeme)
{
	int	equal;
	int	i;

	equal = 0;
	i = 0;
	while (lexeme[i])
	{
		if (equal == 0 && !(ft_isalpha(lexeme[i]) || lexeme[i] == '='))
			return (0);
		else if (lexeme[i] == '=' && i)
			equal++;
		i++;
	}
	if (!equal)
		return (0);
	return (1);
}

char	*env_start(char *env, char *name, int len)
{
	if (ft_strncmp(env, name, len) == 0 && env[len] == '=')
		return (env + len + 1);
	return (NULL);
}

char	**env_clone(char **env)
{
	char	**new;
	int		len;
	int		i;

	len = ft_splitlen(env);
	new = (char **)malloc((len + 1) * sizeof(char *));
	i = 0;
	while (env[i] && new)
	{
		if ((new[i] = sh_strdup(env[i])) == NULL)
		{
			ft_splitclear(new);
			break ;
		}
		i++;
	}
	if (new == NULL)
	{
		g_errno = SH_ENVCERR;
		sh_error();
	}
	return (new);
}
