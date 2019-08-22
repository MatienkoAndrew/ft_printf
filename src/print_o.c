/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:08:46 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/16 14:50:10 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Есть ли флаг #
*/

int		print_zero_for_slash(uintmax_t nbr, t_att *a)
{
	if (a->flag[0] && (nbr || (!nbr && a->prec != -1)))
		return (1);
	return (0);
}

/*
** Функция переводит число из 10сс в 8сс
*/

char	*convert_to_oct(uintmax_t nbr, int *size, int base)
{
	char		*convert;
	int			len;
	uintmax_t	temp;

	temp = nbr;
	*size = (nbr == 0) ? 2 : 1;
	len = *size;
	if (nbr == 0)
	{
		*size = 1;
		return ("0");
	}
	while ((temp /= base))
		len++;
	*size = len;
	if (!(convert = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	convert[len] = '\0';
	while (nbr)
	{
		convert[--len] = nbr % base + '0';
		nbr /= base;
	}
	return (convert);
}

/*
** Переводим число в 8сс
** Определяем есть ли флаги
** Если нету флага '-', то записываем нули
** Если есть флаг '#', то записываем нуль
** Выводим число, если точность не ноль или
** число больше нуля
** Если есть флаг '-', то записываем нули
*/

int		format_unsigned(uintmax_t nbr, t_att *a)
{
	int		len;
	int		zero;
	int		space;
	char	*octal;
	int		sign;

	octal = convert_to_oct(nbr, &len, 8);
	sign = print_zero_for_slash(nbr, a);
	if (!a->prec && !nbr)
		len = 0;
	len += sign;
	zero = get_zero(a, &len, 0);
	space = get_space(a, &len);
	(!a->flag[3]) ? print_splits(space) : 0;
	print_zero_for_slash(nbr, a) ? ft_putchar('0') : 0;
	print_zero(zero);
	if (a->prec != 0 || nbr)
		ft_putstr(octal);
	if (nbr != 0)
		free(octal);
	if (a->flag[3])
		print_splits(space);
	return (len);
}

/*
** Определяется тип, который подался в printf
*/

int		print_o(va_list ap, t_att *attr)
{
	int		len;
	int		length;

	len = 0;
	length = attr->length;
	if (length == 'j')
		len = format_unsigned(va_arg(ap, uintmax_t), attr);
	else if (length == 'z')
		len = format_unsigned(va_arg(ap, size_t), attr);
	else if (length == 'K')
		len = format_unsigned(va_arg(ap, unsigned long long), attr);
	else if (length == 'l')
		len = format_unsigned(va_arg(ap, unsigned long), attr);
	else if (length == 'h')
		len = format_unsigned((unsigned short)va_arg(ap, unsigned int), attr);
	else if (length == 'H')
		len = format_unsigned((unsigned char)va_arg(ap, unsigned int), attr);
	else
		len = format_unsigned(va_arg(ap, unsigned int), attr);
	return (len);
}
