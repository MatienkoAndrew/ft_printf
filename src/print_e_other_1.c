/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_other_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:12:42 by asusan            #+#    #+#             */
/*   Updated: 2019/08/06 19:12:43 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	sum_1(char **drob, t_att *attr, char **res_en, char *perem)
{
	if (*drob != NULL && attr->prec == 0 && (((*drob)[0] >= '5' &&
		((*res_en)[5000] - '0') % 2 != 0) || (*drob)[0] > '5'))
	{
		perem = ft_strnew_float(ft_strlen(*res_en));
		perem[ft_strlen(*res_en) - 1] = '1';
		*res_en = sum(perem, *res_en, ft_strlen(*res_en) - 1);
		free(perem);
	}
}

int		bonus_for_first_helper(char *perem, t_att *attr, char **drob)
{
	if ((perem = ft_strnew_float(attr->prec - 1)))
	{
		perem[attr->prec - 1] = '1';
		*drob = sum(perem, *drob, attr->prec - 1);
	}
	else if ((perem = ft_strnew_float(0)))
	{
		perem[0] = '1';
		*drob = sum(perem, *drob, 0);
	}
	free(perem);
	return (0);
}

int		find_max_power(char *arr)
{
	int	count;
	int	i;

	i = ft_strlen(arr);
	count = 0;
	while (arr[i - count - 1] == '0')
		count++;
	return (i - count);
}

int		find_next_value(char *drob, t_att *attr)
{
	int	i;

	i = attr->prec;
	if ((int)ft_strlen(drob) <= attr->prec)
		return (0);
	while (drob[++i] != '\0')
		if (drob[i] > '0')
			return (1);
	return (0);
}

int		bonus_func_vc_position(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] == '0' && arr[i] != '\0')
		i++;
	return (5001 - i);
}
