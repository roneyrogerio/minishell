/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:34:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/15 21:56:52 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_PATH_H
# define FIND_PATH_H

char	*find_path(char *bin);
char	*absolute_path(char *bin);
char	*relative_path(char *bin);
char	*norminette_does_not_make_sense(char *bin, char *path);
char	*sys_path(char *bin);

#endif
