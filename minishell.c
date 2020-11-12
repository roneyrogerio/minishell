/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 08:18:06 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/11 16:04:35 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

int	main(void)
{
	while (1)
	{
		if (g_errno != 0 || errno != 0)
			sh_error();
		if (read_cmd() == -1)
			continue ;
		sh_free();
	}
	return (0);
}
