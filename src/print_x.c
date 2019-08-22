/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:09:31 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/16 16:25:47 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Определяет есть ли флаг #
** Возвращает 2, так как надо будет напечатать
** 2 символа: 0x(0X)
*/

int		printing_x(uintmax_t nbr, t_att *a)
{
	if ((a->flag[0] && nbr) || a->spec == 'p')
		return (2);
	return (0);
}

/*
** Функция переводит число в 16сс
*/

char	*convert_to_hex1(uintmax_t nbr, int *size, char *b)
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
	while ((temp /= 16))
		len++;
	*size = len;
	if (!(convert = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	convert[len] = '\0';
	while (nbr)
	{
		convert[--len] = b[nbr % 16];
		nbr /= 16;
	}
	return (convert);
}

/*
** Определяется формат, в котором записывать
** число в 16сс
*/

char	*convert_to_hex(uintmax_t nbr, int *size, t_att *a)
{
	char	*base_x;
	char	*base_x1;
	char	*convert;

	convert = NULL;
	if (!(base_x = ft_strdup("0123456789abcdef")))
		return (NULL);
	if (!(base_x1 = ft_strdup("0123456789ABCDEF")))
		return (NULL);
	if (a->spec == 'x' || a->spec == 'p')
		convert = convert_to_hex1(nbr, size, base_x);
	else if (a->spec == 'X')
		convert = convert_to_hex1(nbr, size, base_x1);
	free(base_x);
	free(base_x1);
	return (convert);
}

/*
** Записывает число в 16сс со всеми флагами
*/

int		format_hex(uintmax_t nbr, t_att *a)
{
	int		len;
	int		zero;
	int		space;
	char	*hex;
	int		sign;

	hex = convert_to_hex(nbr, &len, a);
	sign = printing_x(nbr, a);
	if (!a->prec && !nbr)
		len = 0;
	len += sign;
	zero = get_zero(a, &len, sign);
	space = get_space(a, &len);
	(!a->flag[3]) ? print_splits(space) : 0;
	printing_x(nbr, a) ? ft_putchar('0') : 0;
	if (printing_x(nbr, a))
		a->spec == 'X' ? ft_putchar('X') : ft_putchar('x');
	print_zero(zero);
	if (a->prec != 0 || nbr)
		ft_putstr(hex);
	if (nbr != 0)
		free(hex);
	if (a->flag[3])
		print_splits(space);
	return (len);
}

/*
** Определяется тип, который подался в printf
*/

int		print_x(va_list ap, t_att *attr)
{
	int		len;
	int		length;

	len = 0;
	length = attr->length;
	if (attr->spec == 'p')
		len = format_hex((uintmax_t)va_arg(ap, void *), attr);
	else if (length == 'j')
		len = format_hex(va_arg(ap, uintmax_t), attr);
	else if (length == 'z')
		len = format_hex(va_arg(ap, size_t), attr);
	else if (length == 'K')
		len = format_hex(va_arg(ap, unsigned long long), attr);
	else if (length == 'l')
		len = format_hex(va_arg(ap, unsigned long), attr);
	else if (length == 'h')
		len = format_hex((unsigned short)va_arg(ap, unsigned int), attr);
	else if (length == 'H')
		len = format_hex((unsigned char)va_arg(ap, unsigned int), attr);
	else
		len = format_hex(va_arg(ap, unsigned int), attr);
	return (len);
}
