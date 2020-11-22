/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:43:26 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 14:55:53 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_env(char *lexeme)
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

char		*env_start(char *env, char *name, int len)
{
	if (len > 2 && name && name[0] == '{' && name[len - 1] == '}')
	{
		name = &name[1];
		len -= 2;
	}
	if (ft_strncmp(env, name, len) == 0 && env[len] == '=')
		return (env + len + 1);
	return (NULL);
}

t_env_lst	*env_clone(char **env)
{
	t_env_lst	*lst;
	t_env_lst	*item;
	t_env		*content;
	int			i;

	lst = NULL;
	i = 0;
	while (env && env[i])
	{
		if ((content = malloc(sizeof(t_env))) == NULL ||
			(item = ft_lstnew(content)) == NULL ||
			(content->value = ft_strdup(env[i])) == NULL)
		{
			free(content);
			free(item);
			ft_lstclear((void **)&lst, &free);
			g_errno = SH_ENVCERR;
			sh_error();
			return (NULL);
		}
		content->exp = 1;
		ft_lstadd_back((void **)&lst, item);
		i++;
	}
	return (lst);
}
