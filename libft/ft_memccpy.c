/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:30:02 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:18:01 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dst_ptr;
	unsigned char *src_ptr;
	unsigned char c_c;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	c_c = (unsigned char)c;
	while (n--)
	{
		*dst_ptr = *src_ptr++;
		if (*dst_ptr++ == c_c)
			return ((void *)(dst_ptr));
	}
	return (NULL);
}
