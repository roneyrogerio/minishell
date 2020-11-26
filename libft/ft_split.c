/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:52:13 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/27 01:25:03 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

static size_t	words_count(char const *s, char c)
{
	size_t	start;
	size_t	words;

	start = 0;
	words = 0;
	while (*s++)
	{
		if (start == 0 && *(s - 1) != c)
			start = 1;
		if (start == 1 && (*s == c || *s == 0))
		{
			start = 0;
			words++;
		}
	}
	return (words);
}

static size_t	chars_count(char const *s, char c)
{
	size_t	start;
	size_t	chars;

	start = 0;
	chars = 0;
	while (*s++)
	{
		if (start == 0 && *(s - 1) != c)
			start = 1;
		if (start == 1)
			chars++;
		if (start == 1 && (*s == c || *s == 0))
			break ;
	}
	return (chars);
}

char			**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	chars;
	size_t	offset;
	char	**rslt;

	if (!s)
		return (NULL);
	words = words_count(s, c);
	i = 0;
	offset = 0;
	if (!(rslt = (char **)malloc((words + 1) * sizeof(char *))))
		return (NULL);
	while (i < words)
	{
		while (s[offset] == c)
			offset++;
		chars = chars_count(&s[offset], c);
		if (!(rslt[i] = ft_substr(&s[offset], 0, chars)) || !rslt[i])
			return (NULL);
		offset += chars;
		i++;
	}
	rslt[i] = NULL;
	return (rslt);
}
