/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:09:32 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/15 17:49:23 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Здесь в зависимости от спецификатора
** переходим к нужной функции
** Если после процента идет неизвестный
** спецификатор, то просто печатаем этот
** символ - поэтому его вызываем в самом последнем
** else
*/

int		printing(va_list ap, t_att *attr)
{
	int		len;

	len = 0;
	if (attr->spec == 's')
		len = print_s(ap, attr);
	else if (attr->spec == 'd' || attr->spec == 'i')
		len = print_d(ap, attr);
	else if (attr->spec == 'c')
		len = print_c(ap, attr);
	else if (attr->spec == 'f' || attr->spec == 'F')
		len = print_e(ap, attr);
	else if (attr->spec == 'e' || attr->spec == 'E')
		len = print_e(ap, attr);
	else if (attr->spec == 'o')
		len = print_o(ap, attr);
	else if (attr->spec == 'u' || attr->spec == 'U')
		len = print_u(ap, attr);
	else if (attr->spec == 'x' || attr->spec == 'X' || attr->spec == 'p')
		len = print_x(ap, attr);
	else
		len = print_another(attr);
	return (len);
}
