/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:26:38 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/11/15 14:44:24 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_error(char *bin, char *err)
{
	if (err == NULL)
		return ;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(bin, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
}
