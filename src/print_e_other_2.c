/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_other_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:20:13 by asusan            #+#    #+#             */
/*   Updated: 2019/08/06 19:20:15 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*for_nan_inf(t_att *attr, int chooose, long double nbr)
{
	if (chooose == 1)
	{
		if (attr->spec == 'E' || attr->spec == 'F')
			return ("NAN");
		else
			return ("nan");
	}
	else
	{
		if (nbr < 0)
		{
			if (attr->spec == 'E' || attr->spec == 'F')
				return ("-INF");
			else
				return ("-inf");
		}
		else
		{
			if (attr->spec == 'E' || attr->spec == 'F')
				return ("INF");
			else
				return ("inf");
		}
	}
}

char	*sum_for_e(char *exp_five, char *sum_one, int size)
{
	int	ost;
	int	res;
	int	i;

	i = -1;
	ost = 0;
	while (++i <= size + 1)
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

void	installer(int *power, char **drob, char **entire, int k)
{
	*power = k;
	*drob = ft_strnew_float(5000);
	*entire = NULL;
	if (k >= 0)
		*entire = ft_strnew_float(k);
}

int		func_for_output_nan(t_att *attr, char *arr)
{
	int	reter;

	reter = ft_strlen(arr);
	if ((ft_strcmp(arr, "inf") == 0 || ft_strcmp(arr, "INF") == 0)
		&& attr->flag[4] == ' ' && attr->flag[2] != '+')
	{
		ft_putchar(' ');
		reter++;
	}
	if ((ft_strcmp(arr, "inf") == 0 || ft_strcmp(arr, "INF") == 0)
	&& attr->flag[2] == '+')
		reter++;
	if (attr->flag[3] != '-' && reter < attr->width)
		reter = print_splits(attr->width - reter) + reter;
	if ((ft_strcmp(arr, "inf") == 0 || ft_strcmp(arr, "INF") == 0)
	&& attr->flag[2] == '+')
		ft_putchar('+');
	ft_putstr(arr);
	if (attr->flag[3] == '-' && reter < attr->width)
		reter = print_splits(attr->width - reter) + reter;
	return (reter);
}

void	ft_print_for_e(char **res_en, int *i)
{
	if (ft_strlen(*res_en) >= 2 && (*res_en)[ft_strlen(*res_en) - 2] != '0')
		ft_putchar((*res_en)[ft_strlen(*res_en) - 2]);
	else
		ft_putchar((*res_en)[ft_strlen(*res_en) - 1]);
	if (*res_en != NULL)
		free(*res_en);
	*res_en = ft_itoa(*i);
	(*i) = 0;
}
