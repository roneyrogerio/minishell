/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:40:16 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 15:56:08 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct	s_env
{
	char	*value;
	int		exp;
}				t_env;

typedef	struct	s_env_lst
{
	t_env				*content;
	struct s_env_lst	*next;
}				t_env_lst;

int				is_env(char *lexeme);
char			*env_var(char *name, int len);
void			env_lst_clear(void);
char			**env_get(void);
char			*env_start(char *env, char *name, int len);
t_env_lst		*env_clone(char **env);
int				env_len(void);

#endif
