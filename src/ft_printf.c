/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:17:20 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/15 17:20:10 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Определяем есть ли длина
*/

int		len(char c)
{
	if (c == 'l' || c == 'h' || c == 'j' \
			|| c == 'z' || c == 't' \
			|| c == 'L')
		return (1);
	return (0);
}

/*
** Обрезаем строчку от % до спецификатора
*/

char	*parsing(const char **format)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)*format;
	while (temp[i])
	{
		if (temp[i] != '.')
		{
			if (!len(temp[i]) && !ft_isdigit(temp[i]) && temp[i] != '-' \
					&& temp[i] != '+' && temp[i] != '#' && temp[i] != ' '\
					&& temp[i] != '*')
				return (ft_strsub(temp, 0, i + 1));
		}
		i++;
	}
	return (ft_strdup(*format));
}

/*
** Заполняем поля структуры
*/

void	attribute(t_att *attr, char **temp, int length, va_list ap)
{
	int		k;

	k = 0;
	initialize(attr);
	opr_spec(*temp, attr, length);
	while (**temp != attr->spec && length != 0 && **temp)
	{
		while (opr_flag(temp, attr))
			(*temp)++;
		while ((k = opr_width(*temp, attr, ap)))
			*temp += k;
		while ((k = precision(*temp, attr, ap)))
			*temp += k;
		while ((k = opr_len(*temp, attr)))
			*temp += k;
	}
}

/*
** В temp записываем парсер
** in length I write length of format
** and return actually this length
** определяем ширину
** точность, если есть
** и флаг
*/

int		read_flag(va_list ap, const char **format)
{
	t_att	attr;
	int		length;
	char	*temp;
	int		len_pr;
	char	*start;

	temp = parsing(format);
	start = temp;
	length = ft_strlen(temp);
	attribute(&attr, &temp, length, ap);
	len_pr = printing(ap, &attr);
	(length != 0) ? *format += (length - 1) : 0;
	temp = start;
	free(temp);
	temp = NULL;
	if (!**format)
		return (-1);
	return (len_pr);
}

/*
** Головная функция данного проекта
** если встретился процент, то переходим в
** дебри функций
** иначе записываем символ
*/

int		ft_printf(const char *format, ...)
{
	int			count;
	int			length_param;
	va_list		ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if ((length_param = read_flag(ap, &format)) == -1)
				break ;
			count += length_param;
		}
		format++;
	}
	va_end(ap);
	return (count);
}
