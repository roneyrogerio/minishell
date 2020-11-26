/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:38:06 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:15:50 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c_c;
	size_t			i;
	size_t			j;

	i = ft_strlen(s);
	c_c = (unsigned char)c;
	if (!c)
		return ((char *)s + i);
	j = i;
	while (i)
	{
		i--;
		if (s[i] == c_c)
			return ((char *)s + i);
	}
	return (NULL);
}
