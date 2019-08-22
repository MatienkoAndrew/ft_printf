/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:20:04 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/15 16:57:10 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Печатаем precision символов
*/

int		print_prec_symb(t_att *attr, int size, char *str)
{
	int		i;

	i = -1;
	if (attr->prec != -1)
		while (++i < attr->prec && str[i])
			ft_putchar(str[i]);
	else
		while (++i < size)
			ft_putchar(str[i]);
	return (i);
}

/*
** Сначала печатаем символы, потом пробелы
*/

int		print_symb_first(t_att *attr, int size, char *str)
{
	int		i;
	int		split;
	int		k;

	i = -1;
	if (attr->prec == -1 || str[i + 1] == '\0' || attr->prec >= size)
		split = attr->width - size;
	else
		split = attr->width - attr->prec;
	k = print_prec_symb(attr, size, str);
	if (split < 0)
		split = ~split + 1;
	while (++i < split)
		ft_putchar(' ');
	return (split + k);
}

/*
** Сначала печатаем пробелы
** или нули
** потом символы
*/

int		print_split_first(t_att *a, int size, char *str)
{
	int		split;
	int		zero;
	int		i;

	i = -1;
	zero = a->flag[1];
	split = 0;
	if (a->prec == -1 || (a->width >= a->prec && a->prec > size) \
			|| (a->width < a->prec && a->prec > size && a->width >= size) \
			|| str[i + 1] == '\0')
		split = a->width - size;
	else
		split = a->prec == -1 ? a->width - 1 - a->prec : a->width - a->prec;
	if (split < 0)
		split = ~split + 1;
	while (++i < split)
	{
		if (!zero)
			ft_putchar(' ');
		else if (a->width >= size)
			ft_putchar('0');
		else
			break ;
	}
	return (i + print_prec_symb(a, size, str));
}

/*
** В данной функции
** определяется, что печатать
*/

int		print_split(t_att *attr, int size, char *str)
{
	int		width;
	int		prec;
	int		boolean;

	width = attr->width;
	prec = attr->prec;
	boolean = attr->flag[3];
	if (!width || (width < prec && width <= size) || \
			(boolean && (width < prec) && width <= size) \
			|| (width < size && prec == -1))
		return (print_prec_symb(attr, size, str));
	else if ((boolean && (width <= prec)) ||
			((boolean && (width > prec))))
		return (print_symb_first(attr, size, str));
	else if (width == prec || (width > prec) || \
			(boolean && !width) \
			|| (width < prec && prec > size && width + size))
		return (print_split_first(attr, size, str));
	return (0);
}

/*
** Спецификатор: %s
*/

int		print_s(va_list ap, t_att *attr)
{
	char	*str;
	int		size;
	int		len;
	int		flager;

	len = 0;
	flager = 0;
	if (!(str = va_arg(ap, char *)))
	{
		str = ft_strdup("(null)");
		flager = 1;
	}
	size = ft_strlen(str);
	if (attr->prec != -1 || attr->width != 0)
	{
		len = print_split(attr, size, str);
		if (flager == 1)
			free(str);
		return (len);
	}
	ft_putstr(str);
	return (size);
}
