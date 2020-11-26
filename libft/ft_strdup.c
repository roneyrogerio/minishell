/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:06:50 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:17:31 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

char	*ft_strdup(const char *s1)
{
	char	*rslt;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	if (!(rslt = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	while (j <= i)
	{
		rslt[j] = ((char *)s1)[j];
		j++;
	}
	return (rslt);
}
