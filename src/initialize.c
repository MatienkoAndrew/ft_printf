/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:00:01 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/15 17:20:49 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Инициализируем поля структуры
** Ширине присваиваем ноль
** Точности: -1 - это важно, это
** говорит о том, что точки нет
** Длине: \0
** Спецификатору: \0
** И обнулили все флаги
*/

void	initialize(t_att *attr)
{
	attr->width = 0;
	attr->prec = -1;
	attr->length = '\0';
	attr->spec = '\0';
	ft_bzero(attr->flag, 6);
}

void	help_for_opr_len(char *temp, int count, t_att *a)
{
	if (temp[count + 1] == 'l')
		a->length = 'K';
	else
		a->length = 'l';
}

void	help_for_opr_len_1(char *temp, int count, t_att *a)
{
	if (temp[count + 1] == 'h')
		a->length = 'H';
	else
		a->length = 'h';
}
