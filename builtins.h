/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:31:02 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/23 11:02:07 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		builtins(int i);
int		int_echo(int i);
int		int_pwd(void);
int		int_env(void);
int		int_cd(int i);
int		int_export(int i);
void	set_env_exp(char *name);
int		int_unset(int i);
void	unset_env(char *name);

#endif
