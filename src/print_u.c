/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:39:09 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/16 16:39:11 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Функция определяет количество цифр в числе
*/

int		udigits_nbr(uintmax_t nbr)
{
	int		len;

	len = (nbr == 0) ? 1 : 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/*
** Определяем количество цифр в числе
** Определяем количество нулей и пробелов, которые
** должны быть записаны и печатаем их
** Выводим число, если нету точки или число не нуль
** Если есть флаг минус - записываем пробелы
*/

int		unsigned_u(uintmax_t nbr, t_att *a)
{
	int		len;
	int		zero;
	int		space;

	len = 0;
	if (a->prec == -1 || nbr)
		len += udigits_nbr(nbr);
	zero = get_zero(a, &len, 0);
	space = get_space(a, &len);
	(!a->flag[3]) ? print_splits(space) : 0;
	print_zero(zero);
	if (a->prec == -1 || nbr)
		ft_putunbr(nbr);
	(a->flag[3]) ? print_splits(space) : 0;
	return (len);
}

/*
** Определяется тип, который подался в printf
*/

int		print_u(va_list ap, t_att *attr)
{
	int		len;
	int		length;

	len = 0;
	length = attr->length;
	if (length == 'j')
		len = unsigned_u(va_arg(ap, uintmax_t), attr);
	else if (length == 'z')
		len = unsigned_u(va_arg(ap, size_t), attr);
	else if (length == 'K')
		len = unsigned_u(va_arg(ap, unsigned long long), attr);
	else if (length == 'l' || attr->spec == 'U')
		len = unsigned_u(va_arg(ap, unsigned long), attr);
	else if (length == 'h')
		len = unsigned_u((unsigned short)va_arg(ap, unsigned int), attr);
	else if (length == 'H')
		len = unsigned_u((unsigned char)va_arg(ap, unsigned int), attr);
	else
		len = unsigned_u(va_arg(ap, unsigned int), attr);
	return (len);
}
