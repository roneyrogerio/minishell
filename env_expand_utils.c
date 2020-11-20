/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:57:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/20 17:45:52 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_name_len(int i, int j, int k)
{
	int	len;
	int	braces;
	int	alpha;

	braces = 0;
	alpha = 0;
	len = 0;
	if (g_sh.ast[i].argv[j][k] == '{' && (++k) && (++len))
		braces = 1;
	if (g_sh.ast[i].argv[j][k] == '?')
		return (1);
	while (g_sh.ast[i].argv[j][k])
	{
		if (braces && g_sh.ast[i].argv[j][k] == '}' && (++len))
			braces = 0;
		else if (ft_isalpha(g_sh.ast[i].argv[j][k]) && (++len))
			alpha = 1;
		else if (!ft_isalpha(g_sh.ast[i].argv[j][k]))
			break ;
		k++;
	}
	if (braces || !alpha)
		return (0);
	return (len);
}

int		env_middle_len(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (len);
	return (ft_strlen(str));
}
