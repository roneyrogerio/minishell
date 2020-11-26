/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:25:23 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:20:08 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	if (src < dst)
		while (++i <= len)
			dst_ptr[len - i] = src_ptr[len - i];
	else
		while (len--)
			*dst_ptr++ = *src_ptr++;
	return (dst);
}
