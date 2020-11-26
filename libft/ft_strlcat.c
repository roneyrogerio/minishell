/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:41:17 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:16:21 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	offset;
	size_t	src_i;

	dst_len = 0;
	src_len = 0;
	src_i = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	offset = dst_len;
	while (src[src_len])
		src_len++;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (*(src + src_i) && offset != (dstsize - 1))
	{
		*(dst + offset) = *(src + src_i);
		offset++;
		src_i++;
	}
	*(dst + offset) = '\0';
	return (dst_len + src_len);
}
