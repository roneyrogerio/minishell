/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 08:18:06 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 10:59:47 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

int	main(int argc, char **argv, char **env)
{
	signal(SIGINT, handle_sig);
	signal(SIGCHLD, handle_sig);
	signal(SIGQUIT, handle_sig);
	(void)(argc);
	g_sh.name = sh_name(argv[0]);
	if ((g_sh.env = env_clone(env)) == NULL)
		return (EXIT_FAILURE);
	while (1)
	{
		if (g_errno != 0 || errno != 0)
			sh_error();
		sh_free();
		if (read_cmd() == -1 || run_cmd() == -1)
			continue ;
		sh_free();
	}
	return (EXIT_SUCCESS);
}
