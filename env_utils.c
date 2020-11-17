/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:43:26 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/15 13:06:08 by rde-oliv         ###   ########.fr       */
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
