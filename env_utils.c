/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:43:26 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/17 20:14:59 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_env(char *lexeme)
{
	int	i;

	i = 0;
	while (lexeme[i])
	{
		if (lexeme[i] == '=' && i)
			return (1);
		i++;
	}
	return (0);
}

char	*env_start(char *env, char *name)
{
	int	len;

	len = ft_strlen(name);
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
