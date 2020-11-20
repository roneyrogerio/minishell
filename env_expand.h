/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:33:03 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/20 18:24:42 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_ENV_EXPAND_H
# define ARGV_ENV_EXPAND_H

int		env_expand_argv(int i);
void	env_expand_literal(int i, int j, int k);
int		env_expand_real(int i, int j, int k);
char	*env_expand_value(int i, int j, int k);
int		argv_rm_empty(int i, int j);
int		env_name_len(int i, int j, int k);
int		env_middle_len(char *str);

#endif
