/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:06:50 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:19:48 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	needle_i;
	size_t	haystack_i;
	size_t	needle_len;

	needle_i = 0;
	haystack_i = 0;
	needle_len = 0;
	if (!nee[0])
		return ((char *)hay);
	while (nee[needle_len])
		needle_len++;
	while (len && hay[haystack_i] && (len-- - (needle_len - 1)))
	{
		while (hay[haystack_i++] == nee[needle_i++])
			if (!nee[needle_i])
				return ((char *)hay);
		haystack_i = 0;
		needle_i = 0;
		hay++;
	}
	return (NULL);
}
