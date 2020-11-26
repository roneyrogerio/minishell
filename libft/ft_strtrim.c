/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:26:07 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:10:11 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

static unsigned int	is_in_set(char c, char const *set)
{
	while (*set++)
		if (c == *(set - 1))
			return (1);
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	s1_len;
	size_t	start;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = 0;
	i = 0;
	while (s1[i] && is_in_set(s1[i], set) && ++i)
		start++;
	i = s1_len - 1;
	len = s1_len - start;
	while (s1[i] && is_in_set(s1[i], set) && len && --i)
		len--;
	return (ft_substr(s1, start, len));
}
