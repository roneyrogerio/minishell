/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:10:13 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/17 11:27:40 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_CMD_H
# define RUN_CMD_H

int		run_cmd(void);
int		exec_fork(int i);
void	pipeline(int i);
void	redirection(int i);
void	run_error(char *bin, char *code);

#endif
