/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:09:06 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/15 18:03:32 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t		power(intmax_t i)
{
	intmax_t	a;

	a = 1;
	i--;
	while (i > 0)
	{
		a *= 10;
		i--;
	}
	return (a);
}

static void			bags1(intmax_t n, int neg)
{
	if (n == 0)
		ft_putchar('0');
	if (neg == 1)
		ft_putchar('-');
}

void				ft_putnbr(intmax_t n)
{
	int			i;
	intmax_t	temp;
	intmax_t	time;
	int			neg;

	i = 0;
	temp = n;
	neg = (n < 0) ? 1 : 0;
	bags1(n, neg);
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	time = power(i);
	while (i != 0)
	{
		temp = n;
		n < 0 ? ft_putchar(-(temp / time) + '0') : \
			ft_putchar(temp / time + '0');
		n %= time;
		time /= 10;
		i--;
	}
}
