/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:42:42 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:11:14 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	c[10];

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0 && (n = -n))
		ft_putchar_fd('-', fd);
	i = 0;
	while (n > 0)
	{
		c[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(c[i--], fd);
}
