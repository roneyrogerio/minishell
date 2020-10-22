/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:09:46 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/10/22 09:07:28 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stddef.h>
# include "tokens.h"
# include "lexer.h"
# include "libft/libft.h"

int		g_errno;
int		read_cmd(void);
int		parser(char *line);
void	sh_error(void);
char	*sh_strerror(int errnum);
void	sh_free(void);

/*
** SH errors
*/
# define SH_MEMERR 1
# define SH_SYNERR 2

#endif
