/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:41:24 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:15:29 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_c;
	size_t			i;

	i = 0;
	c_c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(&s[i]));
		i++;
	}
	if (c == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}
