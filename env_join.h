/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_join.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:43:00 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/26 11:59:34 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_JOIN_H
# define ENV_JOIN_H

int		env_join(int i);
int		env_join_new(char *env, int exp);
int		env_join_same(int i, int j);
int		env_join_name_len(char *str);

#endif
