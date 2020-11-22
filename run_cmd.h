/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:10:13 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/22 19:12:32 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_CMD_H
# define RUN_CMD_H

int		run_cmd(void);
int		run_cmd_exec_argv(int i);
int		exec_fork(int i);
int		exec_fork_prepare(int i);
void	pipeline(int i);
void	redirection(int i);
void	run_error(char *bin, char *code);

#endif
