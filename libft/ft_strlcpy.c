/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:31:18 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:12:46 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (!dst && !src)
		return (0);
	while (src[c])
		++c;
	while (dstsize && src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize)
		dst[i] = '\0';
	return (c);
}
