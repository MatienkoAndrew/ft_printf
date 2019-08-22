/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:49:16 by asusan            #+#    #+#             */
/*   Updated: 2019/08/12 19:49:18 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	for_norminette(int *do_this, t_att *attr, int spec_e)
{
	if (attr->flag[3] == '-')
	{
		(*do_this + attr->prec >= attr->width) ?
		(*do_this = attr->prec + *do_this)
		: (*do_this = print_splits(attr->width - *do_this - attr->prec - spec_e)
				+ *do_this + attr->prec);
	}
}

void	for_norminette_1(int i, int *do_this, t_att *attr)
{
	if (i / 100 >= 1)
	{
		(*do_this + attr->prec >= attr->width) ?
		(*do_this = attr->prec + *do_this) :
		(*do_this = print_splits(attr->width - *do_this - attr->prec - 5) +
					*do_this + attr->prec);
	}
	else
	{
		(*do_this + attr->prec >= attr->width) ?
		(*do_this = attr->prec + *do_this) :
		(*do_this = print_splits(attr->width - *do_this - attr->prec - 4)
					+ *do_this + attr->prec);
	}
}

void	for_norminette_2(int i, int *do_this, t_att *attr)
{
	if (i / 100 >= 1)
	{
		(*do_this + attr->prec >= attr->width) ?
		(*do_this = attr->prec + *do_this) :
		(*do_this = print_zero(attr->width - *do_this - attr->prec - 5) +
					*do_this + attr->prec);
	}
	else
	{
		(*do_this + attr->prec >= attr->width) ?
		(*do_this = attr->prec + *do_this) :
		(*do_this = print_zero(attr->width - *do_this - attr->prec - 4) +
					*do_this + attr->prec);
	}
}

void	for_norminette_3(char **res_en, char **drob, char **temp)
{
	if ((*((*res_en) + 1) != '\0' && **res_en == '0') || **drob == '\0')
		(*temp)[1] = '+';
	else
		(*temp)[1] = '-';
}

void	for_norminette_4(char **drob, char **res_en)
{
	char *time;

	time = ft_strdup(*drob);
	free(drob);
	*drob = ft_strjoin(*res_en + 2, time);
	free(time);
	free(*res_en);
	*res_en = ft_strsub(*res_en, 0, 2);
}
