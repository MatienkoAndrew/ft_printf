/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:45:06 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/21 17:37:11 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Длинная арифметика: произведение на 5
** или возведение в любую степень пятерки
*/

int		position(char *arr)
{
	int	j;
	int	i;

	i = 0;
	j = 5000;
	while (arr[i] == '0' && arr[i] != '\0')
		i++;
	while (arr[j] == '0' && j >= 0)
		j--;
	if (j < 0)
		return (0);
	return (j - i + 1);
}

char	*mult_five(int power, int k, char *res, int max_power)
{
	intmax_t	proizv;
	intmax_t	ost;
	int			count;
	int			i;

	i = 0;
	count = 0;
	ost = 0;
	res[k - max_power + power] = '1';
	while (count < power)
	{
		proizv = 5 * (res[k - i - max_power + power] - '0') + ost;
		ost = 0;
		if (proizv >= 10)
			ost = proizv / 10;
		proizv = proizv % 10;
		res[k - i - max_power + power] = proizv + '0';
		if (proizv == 0 && ost == 0 && position(res) < i)
		{
			i = -1;
			count++;
		}
		i++;
	}
	return (res);
}

/*
** Пропускает нолики и записывает число
*/

int		ft_putstr_float(char *str)
{
	int i;

	i = 0;
	while (*str == '0')
		str++;
	if (*str == '\0')
		ft_putchar('0');
	while (*str)
	{
		i++;
		ft_putchar(*str);
		str++;
	}
	return (i);
}

/*
** Длинная арифметика: произведение на 2
** или возведение в любую степень двойки
*/

char	*mult_two(int power, int k, char *res)
{
	intmax_t	proizv;
	intmax_t	ost;
	int			count;
	int			i;

	i = 0;
	count = 0;
	ost = 0;
	res[k] = '1';
	while (count < power)
	{
		proizv = 2 * (res[k - i] - '0') + ost;
		ost = 0;
		if (proizv >= 10)
			ost = proizv / 10;
		proizv = proizv % 10;
		res[k - i] = proizv + '0';
		if (proizv == 0 && ost == 0 && position(res) < i)
		{
			i = -1;
			count++;
		}
		i++;
	}
	return (res);
}

/*
** Длинная арифметика: сложение
*/

char	*sum(char *exp_five, char *sum_one, int size)
{
	int	ost;
	int	res;
	int	i;

	i = -1;
	ost = 0;
	while (++i < size + 1)
	{
		res = ((exp_five[size - i] - '0') + (sum_one[size - i] - '0') + ost);
		ost = 0;
		if (res >= 10)
			ost = res / 10;
		res %= 10;
		sum_one[size - i] = res + '0';
	}
	if (ost != 0)
		return (NULL);
	return (sum_one);
}
