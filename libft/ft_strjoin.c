/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:44:31 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:20:46 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rslt;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	if (!(rslt = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (NULL);
	while ((s1_len + s2_len) > i)
	{
		if (s1_len > i)
			rslt[i] = s1[i];
		else
			rslt[i] = s2[i - s1_len];
		i++;
	}
	rslt[i] = 0;
	return (rslt);
}
