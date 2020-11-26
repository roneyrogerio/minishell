/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:27:15 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:29:33 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

int		ft_atoi(const char *str)
{
	size_t				i;
	unsigned long long	n;
	unsigned long long	mlt;

	i = 0;
	n = 0;
	mlt = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 45)
		mlt = 2;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	if (n > 9223372036854775807)
		return (mlt == 2 ? 0 : -1);
	return (mlt == 2 ? n * -1 : n);
}
