/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:46:38 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/09 11:33:15 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

typedef struct	s_token
{
	int				name;
	char			*value;
	struct s_token	*prev;
	struct s_token	*next;

}				t_token;

t_token			*g_tokens;
t_token			*token_new(int name, char *value);
void			tokens_add(t_token **tokens, t_token *token);
t_token			*token_last(t_token *token);
void			tokens_clear(void);

/*
** dictionary of tokens
*/
# define NEWLINE '\n'
# define LESS '<'
# define GREAT '>'
# define DGREAT 256
# define PIPE '|'
# define SEMI ';'
# define LITERAL 257
# define ENV 258

#endif
