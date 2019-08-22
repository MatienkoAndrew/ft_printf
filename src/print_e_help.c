/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:02:43 by asusan            #+#    #+#             */
/*   Updated: 2019/08/05 17:03:08 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	helper_for_presicion_1(t_att *attr, char **temp, char **res_en, int *i)
{
	*temp = (char*)malloc(7);
	while (*((*res_en) + 1) == '0' && **res_en != '\0')
		++(*res_en);
	if (**res_en == '\0')
		*i = ft_strlen(*res_en) - 1;
	else
		*i = ft_strlen(*res_en) - 2;
	if (*i < 0)
		*i = 0;
	if (attr->spec == 'e')
		(*temp)[0] = 'e';
	else
		(*temp)[0] = 'E';
	return (0);
}

int	helper_for_presicion_2(char **temp, char **res_en, char **drob, int *i)
{
	for_norminette_3(res_en, drob, temp);
	if (*((*res_en) + 1) == '\0' && **res_en == '0' && **drob != '\0')
	{
		*i = 1;
		while (**drob == '0')
		{
			(*i)++;
			(*drob)++;
		}
		free(*res_en);
		*res_en = ft_strsub(*drob, 0, 2);
		if ((*res_en)[0] != '0')
		{
			(*res_en)[1] = (*res_en)[0];
			(*res_en)[0] = '0';
		}
		*drob += 1;
	}
	else
		for_norminette_4(drob, res_en);
	return (0);
}

int	helper_for_presicion_3(char **res_en, char **temp, int *i)
{
	if (ft_strlen(*res_en) >= 2 && (*res_en)[0] != '0')
	{
		if ((*temp)[1] == '+')
			(*i)++;
		else
			(*i)--;
	}
	return (0);
}

int	helper_for_presicion_4(char **res_en, char **temp, int *i, int *do_this)
{
	ft_print_for_e(res_en, i);
	if (ft_strlen(*res_en) < 2)
	{
		while ((*res_en)[*i] != '\0')
		{
			(*temp)[2] = '0';
			(*temp)[*i + 3] = (*res_en)[*i];
			(*i)++;
		}
		(*temp)[*i + 3] = '\0';
	}
	else
	{
		while ((*res_en)[*i] != '\0')
		{
			(*temp)[*i + 2] = (*res_en)[*i];
			(*i)++;
		}
		(*temp)[*i + 2] = '\0';
		if (*i == 3)
			(*do_this)++;
	}
	return (0);
}

int	helper_for_presicion_5(t_att *attr, int *do_this, int i, int sign)
{
	if ((attr->spec == 'e' || attr->spec == 'E')
		&& attr->flag[3] != '-' && attr->flag[1] != '0')
		for_norminette_1(i, do_this, attr);
	else if ((attr->spec == 'f' || attr->spec == 'F') &&
	attr->flag[3] != '-' && attr->flag[1] != '0')
	{
		(*do_this + attr->prec >= attr->width) ?
		(*do_this = attr->prec + *do_this) :
		(*do_this = print_splits(attr->width - *do_this - attr->prec) +
				*do_this + attr->prec);
	}
	out_sign(sign, attr);
	if ((attr->spec == 'e' || attr->spec == 'E') &&
	attr->flag[1] == '0' && attr->flag[3] != '-')
		for_norminette_2(i, do_this, attr);
	else if ((attr->spec == 'f' || attr->spec == 'F') &&
	attr->flag[1] == '0' && attr->flag[3] != '-')
	{
		(*do_this + attr->prec >= attr->width) ?
		(*do_this = attr->prec + *do_this) :
		(*do_this = print_zero(attr->width - *do_this - attr->prec) +
				*do_this + attr->prec);
	}
	return (0);
}
