/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:49:17 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:16:42 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_ptr;
	unsigned char *src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (n--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
