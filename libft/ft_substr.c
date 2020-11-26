/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:37:20 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:08:50 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;

	if (!s || !(ptr = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	j = 0;
	while (j < len && ft_strlen(s) > start && (j += 1))
		ptr[j - 1] = s[j - 1 + start];
	ptr[j] = '\0';
	return (ptr);
}
