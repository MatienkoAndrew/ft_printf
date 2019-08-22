/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:36:18 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/15 17:24:39 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Спецификатор: любой иной
*/

int		print_another(t_att *attr)
{
	int		size;
	int		length;
	char	a[2];
	char	c;

	c = attr->spec;
	a[0] = c;
	a[1] = '\0';
	size = 1;
	length = 1;
	if (attr->width)
		length = print_split(attr, size, a);
	else
	{
		if (c != '\0' && c != ' ' && !len(c))
			ft_putchar(c);
		else
			length = 0;
	}
	return (length);
}

/*
** Спецификатор: %c
*/

int		print_c(va_list ap, t_att *attr)
{
	char	c;
	int		size;
	int		len;
	char	a[2];

	if (attr->spec == 'c')
		c = va_arg(ap, int);
	else
		c = attr->spec;
	a[0] = c;
	a[1] = '\0';
	size = 1;
	len = 1;
	if (attr->width)
		len = print_split(attr, size, a);
	else
		ft_putchar(c);
	return (len);
}
