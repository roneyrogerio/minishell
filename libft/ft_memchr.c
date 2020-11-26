/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:05:22 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:30:28 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	unsigned char	c_c;

	s_ptr = (unsigned char *)s;
	c_c = (unsigned char)c;
	while (n--)
		if (*s_ptr++ == c_c)
			return (--s_ptr);
	return (NULL);
}
