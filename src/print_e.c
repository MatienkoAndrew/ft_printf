/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:28:58 by asusan            #+#    #+#             */
/*   Updated: 2019/08/01 12:28:59 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		long_ariphmetic_drob_e(char *drob, t_att *attr, char *res_en)
{
	int		power;
	char	*res_drob;
	char	*rese_tmp;
	int		max_power;

	power = 1;
	max_power = find_max_power(drob);
	res_drob = ft_strnew_float(5000);
	while (*drob != '\0')
	{
		if (*drob == '1')
		{
			rese_tmp = ft_strnew_float(5000);
			rese_tmp = mult_five(power, 5000, rese_tmp, max_power);
			res_drob = sum(rese_tmp, res_drob, 5000);
			free(rese_tmp);
			rese_tmp = NULL;
		}
		power++;
		drob++;
	}
	res_drob[5000 - max_power] = '.';
	power = give_me_true_presicion_e(res_drob, attr, res_en);
	free(res_drob);
	return (power);
}

int		long_ariphmetic_entire_e(char *entire, char *drob,
		int power, t_att *attr)
{
	char	*res_en;
	char	*tmp;
	int		size;
	int		width;

	size = 5000;
	res_en = NULL;
	res_en = ft_strnew_float(5000);
	while (entire != NULL && *entire != '\0')
	{
		if (*entire == '1')
		{
			tmp = ft_strnew_float(size);
			tmp = mult_two(power, size, tmp);
			res_en = sum(tmp, res_en, size);
			free(tmp);
		}
		power--;
		entire++;
	}
	width = long_ariphmetic_drob_e(drob, attr, res_en);
	free(res_en);
	return (width);
}

int		helper_e(int k, t_float_u floating, t_att *attr)
{
	int		i;
	int		power;
	char	*drob;
	char	*entire;

	installer(&power, &drob, &entire, k);
	i = 64;
	while (i--)
	{
		if (k >= 0)
		{
			if ((floating.bytes.mantisa >> i) & 1)
				entire[power - k] = '1';
		}
		else
		{
			if ((floating.bytes.mantisa >> i) & 1)
				drob[-k - 1] = '1';
		}
		k--;
	}
	i = long_ariphmetic_entire_e(entire, drob, power, attr);
	free(entire);
	free(drob);
	return (i);
}

int		format_double_e(long double nbr, t_att *attr)
{
	int			len;
	int			k;
	t_float_u	floating;

	if (nbr != nbr)
		return (func_for_output_nan(attr, for_nan_inf(attr, 1, nbr)));
	if (nbr / 10 == nbr * 10 && nbr != 0.)
	{
		if (nbr < 0)
			return (func_for_output_nan(attr, for_nan_inf(attr, 0, nbr)));
		return (func_for_output_nan(attr, for_nan_inf(attr, 0, nbr)));
	}
	floating.f = nbr;
	k = floating.bytes.exponent - 16383;
	if ((floating.bytes.sign) & 1)
	{
		attr->length = 1;
		len = helper_e(k, floating, attr);
	}
	else
	{
		attr->length = 0;
		len = helper_e(k, floating, attr);
	}
	return (len);
}

int		print_e(va_list ap, t_att *attr)
{
	int		len;
	int		length;

	len = 0;
	length = attr->length;
	if (attr->prec == -1)
		attr->prec = 6;
	if (length == 'L')
		len = format_double_e(va_arg(ap, long double), attr);
	else
		len = format_double_e((long double)va_arg(ap, double), attr);
	return (len);
}
