/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:30:24 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/15 17:40:00 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Определяется количество пробелов, которые могут
** быть записаны в зависимости от флагов
*/

int		get_space(t_att *a, int *len)
{
	int		space;

	space = 0;
	if (a->width && \
			(!a->flag[1] || a->flag[3] || a->prec || a->prec == 0) \
			&& a->width > *len)
	{
		space = a->width - *len;
		*len += space;
	}
	return (space);
}

/*
** Определяется количество нулей, которые могут
** быть записаны в зависимости от флагов
*/

int		get_zero(t_att *a, int *len, int sign)
{
	int		zeros;

	zeros = 0;
	if (a->prec && a->prec > *len - sign)
	{
		zeros = a->prec - (*len - sign);
		*len += zeros;
	}
	if (a->width && a->flag[1] && !a->flag[3] && \
			a->prec == -1 && a->width > *len)
	{
		zeros += a->width - *len;
		*len += zeros;
	}
	return (zeros);
}

/*
** Если есть флаг ' ' или '+'
** то он записывается
** если число отрицательное, то пишется
** знак '-'
*/

void	print_sign(intmax_t nbr, t_att *a)
{
	char	sign;

	sign = 0;
	if (nbr < 0)
		ft_putchar('-');
	else
	{
		if (a->flag[2])
			ft_putchar('+');
		else if (a->flag[4])
			ft_putchar(' ');
	}
}

/*
** Записывается число
*/

int		format_signed(intmax_t nbr, t_att *a)
{
	int		len;
	int		sign;
	int		zero;
	int		space;

	len = 0;
	sign = (nbr >= 0 && (a->flag[2] || a->flag[4])) ? 1 : 0;
	if (a->prec == -1 || nbr)
		len += digits_nbr(nbr);
	len += sign;
	zero = get_zero(a, &len, (nbr < 0 || sign));
	space = get_space(a, &len);
	(!a->flag[3]) ? print_splits(space) : 0;
	print_sign(nbr, a);
	print_zero(zero);
	if (a->prec == -1 || nbr)
		ft_putunbr((nbr >= 0) ? (nbr) : (-nbr));
	(a->flag[3]) ? print_splits(space) : 0;
	return (len);
}

/*
** Определяется тип, который подался в printf
*/

int		print_d(va_list ap, t_att *attr)
{
	int		len;
	int		length;

	len = 0;
	length = attr->length;
	if (length == 'j' || length == 'z')
		len = format_signed(va_arg(ap, intmax_t), attr);
	else if (length == 'l')
		len = format_signed(va_arg(ap, long), attr);
	else if (length == 'K')
		len = format_signed(va_arg(ap, long long), attr);
	else if (length == 'h')
		len = format_signed((short)va_arg(ap, int), attr);
	else if (length == 'H')
		len = format_signed((char)va_arg(ap, int), attr);
	else
		len = format_signed(va_arg(ap, int), attr);
	return (len);
}
