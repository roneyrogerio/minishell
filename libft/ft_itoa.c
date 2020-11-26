/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:26:20 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 03:52:26 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

char	*ft_itoa(int n)
{
	long	nb;
	long	mlt;
	int		count;
	char	*rslt;

	nb = n;
	mlt = 1;
	count = 1;
	while ((nb < 0 ? -nb : nb) / (10 * mlt) > 0 && (mlt *= 10))
		count++;
	if (nb < 0)
		count++;
	if (!(rslt = (char *)malloc((count + 1) * sizeof(char))))
		return (NULL);
	rslt[count] = '\0';
	if (nb == 0 && (rslt[0] = 48))
		return (rslt);
	if (nb < 0 && (nb = -nb))
		rslt[0] = '-';
	while (nb > 0 && count--)
	{
		rslt[count] = nb % 10 + 48;
		nb /= 10;
	}
	return (rslt);
}
