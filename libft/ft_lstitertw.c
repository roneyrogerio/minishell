/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstitertw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:38:05 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/18 08:48:23 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

void	ft_lstitertw(t_list *lst, void *p, void (*f)(void *, void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content, p);
		lst = lst->next;
	}
}
