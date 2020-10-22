/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:49:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/10/21 11:57:15 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stddef.h>
# include "tokens.h"

typedef struct	s_lx
{
	char	*line;
	char	*cache;
	size_t	i;
	int		qte;
	int		dqte;
}				t_lx;

t_lx			g_lx;
t_token			*lexer(char *line);
t_token			*lx_literal(void);
char			*lexeme(void);
void			lexeme_join(char **value);
t_token			*lx_special(void);
int				lx_isspecial(void);
int				lx_isliteral(void);
int				lx_isqte(void);
void			lx_cachejoin(char *value);
int				lx_islexeme();

#endif
