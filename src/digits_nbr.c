/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:32:36 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/15 17:47:51 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Печатает определенное количество пробелов
*/

int		print_splits(int space)
{
	int		i;

	i = -1;
	while (++i < space)
		ft_putchar(' ');
	return (i);
}

/*
** Печатает определенное количество нулей
*/

int		print_zero(unsigned long int zero)
{
	unsigned long int	i;

	i = 0;
	while (i < zero)
	{
		i++;
		ft_putchar('0');
	}
	return (i);
}

/*
** Записывает число в output
*/

void	ft_putunbr(uintmax_t nbr)
{
	char	c;

	if (nbr < 10)
	{
		c = nbr + '0';
		ft_putchar(c);
	}
	else
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
}

/*
** Определяется количество цифр в числе
** если число отрицательное, на функция вернет
** на +1 большее число
*/

int		digits_nbr(intmax_t nbr)
{
	int	len;

	len = (nbr >= 0) ? 1 : 2;
	while ((nbr /= 10))
		len++;
	return (len);
}
