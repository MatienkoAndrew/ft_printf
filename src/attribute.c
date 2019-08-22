/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:54:14 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/15 17:03:38 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Длина
** записываем в поле length
*/

int		opr_len(char *temp, t_att *a)
{
	int		count;

	count = 0;
	while ((temp[count] == 'l' || temp[count] == 'h' || \
			temp[count] == 'j' || temp[count] == 'z' \
			|| temp[count] == 'L'))
	{
		if (temp[count] == 'l')
			help_for_opr_len(temp, count, a);
		else if (temp[count] == 'h' && a->length != 'l' && a->length != 'K' \
				&& a->length != 'z' && a->length != 'j')
			help_for_opr_len_1(temp, count, a);
		else if (temp[count] == 'j')
			a->length = 'j';
		else if (temp[count] == 'z')
			a->length = 'z';
		else if (temp[count] == 't')
			a->length = 't';
		else if (temp[count] == 'L')
			a->length = 'L';
		count++;
		(a->length == 'K' || a->length == 'H') ? count++ : 0;
	}
	return (count);
}

/*
** Другие флаги: #0+-' '
** Если флаг уже был, то его не записываем
*/

int		opr_flag(char **format, t_att *att)
{
	if (ft_strchr(att->flag, **format) == NULL)
	{
		(**format == '#') ? att->flag[0] = '#' : 0;
		(**format == '0') ? att->flag[1] = '0' : 0;
		(**format == '+') ? att->flag[2] = '+' : 0;
		(**format == '-') ? att->flag[3] = '-' : 0;
		(**format == ' ') ? att->flag[4] = ' ' : 0;
	}
	return (**format == '#' || **format == '+' \
			|| **format == '0' || **format == '-' \
			|| **format == ' ');
}

int		precision(char *temp, t_att *p, va_list ap)
{
	long long int	precision;
	char			*nbr;

	precision = 0;
	if (temp[0] == '.')
	{
		precision = 1;
		if (temp[1] == '*')
		{
			p->prec = va_arg(ap, int);
			precision++;
		}
		else
		{
			while (ft_isdigit(temp[precision]))
				precision++;
			if (!(nbr = ft_strsub(temp, 1, precision)))
				return (0);
			p->prec = (precision != 1) ? ft_atoi_for_f(nbr) : 0;
			free(nbr);
		}
	}
	return (precision);
}

int		opr_width(char *format, t_att *w, va_list ap)
{
	int		width;
	char	*nbr;

	width = 0;
	if (*format == '*')
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			width = ~width + 1;
			w->flag[5] = '-';
		}
		w->width = width;
		return (1);
	}
	else
	{
		while (ft_isdigit(format[width]))
			width++;
		if (!width || !(nbr = ft_strsub(format, 0, width)))
			return (0);
		w->width = ft_atoi_for_f(nbr);
		free(nbr);
	}
	return (width);
}

/*
** Спецификатор находится последним - выбираем его
** если ни один не подходит, то спецификатор - *format
*/

void	opr_spec(char *format, t_att *fl, int length)
{
	if (length > 0)
		format += length - 1;
	(*format == 's') ? (fl->spec = 's') : 0;
	(*format == 'c') ? (fl->spec = 'c') : 0;
	(*format == 'd') ? (fl->spec = 'd') : 0;
	(*format == 'i') ? (fl->spec = 'i') : 0;
	(*format == 'u') ? (fl->spec = 'u') : 0;
	(*format == 'p') ? (fl->spec = 'p') : 0;
	(*format == 'x') ? (fl->spec = 'x') : 0;
	(*format == 'X') ? (fl->spec = 'X') : 0;
	(*format == 'o') ? (fl->spec = 'o') : 0;
	(*format == 'e') ? (fl->spec = 'e') : 0;
	(*format == 'E') ? (fl->spec = 'E') : 0;
	(*format == 'f') ? (fl->spec = 'f') : 0;
	(*format == 'F') ? (fl->spec = 'F') : 0;
	(*format == 'c') ? (fl->spec = 'c') : 0;
	(*format == 'U') ? (fl->spec = 'U') : 0;
	(*format == '%') ? (fl->spec = '%') : 0;
	(fl->spec == '\0') ? (fl->spec = *format) : 0;
}
