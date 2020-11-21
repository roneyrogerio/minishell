/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand_set.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:33:03 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/21 16:49:38 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_ENV_EXPAND_SET_H
# define ARGV_ENV_EXPAND_SET_H

int		env_expand_set(int i);
void	expand_set_literal(int i, int j, int k);
int		expand_set_real(int i, int j, int k);
char	*expand_set_value(int i, int j, int k);
int		env_set_name_len(int i, int j, int k);
int		set_middle_len(char *str);

#endif
