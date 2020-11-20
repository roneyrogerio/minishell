/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:29:48 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/20 19:36:12 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path(char *bin)
{
	char	*path;

	path = NULL;
	if (bin && bin[0] == '/')
		path = absolute_path(bin);
	else if (bin && ft_strchr(bin, '/'))
		path = relative_path(bin);
	else if (bin && !(bin[0] == '.' && bin[1] == '\0'))
	{
		path = sys_path(bin);
		if (path == NULL && (g_sh.status = 127))
		{
			run_error(bin, "command not found");
			return ("");
		}
	}
	return (path);
}

char	*absolute_path(char *bin)
{
	struct stat sb;

	if (stat(bin, &sb) == -1)
	{
		g_sh.status = 127;
		run_error(bin, strerror(errno));
		errno = 0;
		return (NULL);
	}
	if (S_ISDIR(sb.st_mode))
	{
		run_error(bin, "Is a directory");
		g_sh.status = 126;
		return (NULL);
	}
	return (sh_strdup(bin));
}

char	*relative_path(char *bin)
{
	char		buf[1000];
	char		*path;
	char		*ptr;
	struct stat	sb;

	if (bin && bin[0] == '.' && bin[1] == '/')
		path = ft_strjoin(getcwd(buf, 1000), &bin[1]);
	else if ((path = ft_strjoin("/", bin)) != NULL)
	{
		ptr = path;
		path = ft_strjoin(getcwd(buf, 1000), path);
		free(ptr);
	}
	if (path != NULL && stat(path, &sb) == -1 && (g_sh.status = 127))
	{
		free(path);
		run_error(bin, strerror(errno));
		errno = 0;
		return (NULL);
	}
	if (path != NULL && S_ISDIR(sb.st_mode) && (g_sh.status = 126))
		return (norminette_does_not_make_sense(bin, path));
	if (path == NULL && (g_sh.status = 2))
		g_errno = SH_PATHERR;
	return (path);
}

char	*norminette_does_not_make_sense(char *bin, char *path)
{
	free(path);
	run_error(bin, "Is a directory");
	return (NULL);
}

char	*sys_path(char *bin)
{
	char		*path;
	char		**paths;
	int			i;
	struct stat	sb;

	paths = ft_split(env_var("PATH", 4), ':');
	bin = ft_strjoin("/", bin);
	i = 0;
	while ((path = NULL) == NULL && paths != NULL && bin != NULL && paths[i])
	{
		path = ft_strjoin(paths[i], bin);
		if (path == NULL && (g_errno = SH_PATHERR))
			break ;
		if (stat(path, &sb) != -1)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	if (paths == NULL || bin == NULL)
		g_errno = SH_PATHERR;
	errno = 0;
	ft_splitclear(paths);
	free(bin);
	return (path);
}
