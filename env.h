/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:40:16 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/19 20:46:06 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

int		is_env(char *lexeme);
char	*env_var(char *name, int len);
char	*env_start(char *env, char *name, int len);
char	**env_clone(char **env);

#endif
