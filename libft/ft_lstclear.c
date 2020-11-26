/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:56:01 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/10 06:23:03 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = next;
	}
	*lst = NULL;
}
