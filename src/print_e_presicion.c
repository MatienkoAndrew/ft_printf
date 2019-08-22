/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_presicion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:22:42 by asusan            #+#    #+#             */
/*   Updated: 2019/08/06 19:22:44 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	first_helper_for_presicion_e(char **drob, t_att *attr,
			int *do_this, char **res_en)
{
	char	*perem;

	perem = NULL;
	if (**drob != '\0' && (*drob)[attr->prec] >= '5'
		&& find_next_value(*drob, attr))
		*do_this = 1;
	if (**drob != '\0' && *do_this)
		bonus_for_first_helper(perem, attr, drob);
	if (!(*drob))
	{
		perem = ft_strnew_float(ft_strlen(*res_en));
		perem[ft_strlen(*res_en) - 1] = '1';
		if (attr->spec == 'e' || attr->spec == 'E')
			*res_en = sum_for_e(perem, *res_en, ft_strlen(*res_en) - 1);
		else if (attr->spec == 'f' || attr->spec == 'F')
			*res_en = sum(perem, *res_en, ft_strlen(*res_en) - 1);
		free(perem);
	}
}

int		second_helper_for_presicion_e(char **drob, t_att *attr, char **res_en)
{
	char	*perem;
	int		do_this;

	do_this = 0;
	perem = NULL;
	if (drob != NULL && *drob != NULL && **drob != '\0')
		(attr->prec > 0) ? (*drob = ft_strsub(*drob, 0, attr->prec))
			: (*drob = ft_strsub(*drob, 0, 1));
	if (drob != NULL && *drob != NULL && **drob != '\0'
		&& (attr->flag[0] == '#' || attr->prec > 0))
	{
		if (attr->prec > 0)
		{
			perem = ft_strdup(*drob);
			free(*drob);
			*drob = ft_strjoin(".", perem);
			free(perem);
		}
		do_this = 1;
	}
	sum_1(drob, attr, res_en, perem);
	return (bonus_for_second_helper(attr, res_en, do_this));
}

int		third_helper_for_presicion_e(char **drob, t_att *attr,
			int *do_this, char **res_en)
{
	int	helper;
	int	spec_e;

	spec_e = 0;
	if (attr->spec == 'e' || attr->spec == 'E')
		spec_e = 4;
	helper = 0;
	if (position(*res_en) <= 0 && attr->prec <= 0 && attr->flag[0] != '#')
		(*do_this)--;
	if (attr->length > 0 || attr->flag[2] == '+' || attr->flag[4] == ' ')
		++(*do_this);
	if (drob != NULL && *drob != NULL && position(*res_en) >= 1
		&& **drob == '\0' && (attr->prec > 0 || attr->flag[0] == '#'))
		++(*do_this);
	if (*drob == NULL && attr->prec > 0)
	{
		helper = 1;
		++(*do_this);
	}
	return (helper);
}

int		fourth_helper_for_presicion_e(char **drob, t_att *attr,
			int *do_this, char *temp)
{
	int	spec_e;

	spec_e = 0;
	if (attr->spec == 'e' || attr->spec == 'E')
		spec_e = 4;
	if (drob && *drob && **drob != '\0')
	{
		if (attr->prec != 0)
			ft_putstr_float(*drob);
		else if (attr->flag[0] == '#')
			ft_putchar('.');
		if ((int)(ft_strlen(*drob) - 1) < attr->prec)
			print_zero(attr->prec - ft_strlen(*drob) + 1);
	}
	else if (attr->prec != 0 || attr->flag[0] != '\0')
	{
		ft_putchar('.');
		if (!(*drob) && attr->length == 0)
			++(*do_this);
		print_zero(attr->prec);
	}
	if (attr->spec == 'e' || attr->spec == 'E')
		ft_putstr(temp);
	for_norminette(do_this, attr, spec_e);
	return (*do_this);
}

int		give_me_true_presicion_e(char *drob, t_att *attr, char *res_en)
{
	int		do_this;
	int		i;
	char	*temp;
	int		sign;

	sign = attr->length;
	install_fu(&i, &do_this, &temp);
	if (attr->spec == 'e' || attr->spec == 'E')
		helper_for_presicion_1(attr, &temp, &res_en, &i);
	give_me_value_for_drob(&drob);
	if (attr->spec == 'e' || attr->spec == 'E')
		helper_for_presicion_2(&temp, &res_en, &drob, &i);
	first_helper_for_presicion_e(&drob, attr, &do_this, &res_en);
	do_this = second_helper_for_presicion_e(&drob, attr, &res_en);
	if (attr->spec == 'e' || attr->spec == 'E')
		helper_for_presicion_3(&res_en, &temp, &i);
	attr->length = third_helper_for_presicion_e(&drob, attr, &do_this, &res_en);
	helper_for_presicion_5(attr, &do_this, i, sign);
	if (attr->spec == 'e' || attr->spec == 'E')
		helper_for_presicion_4(&res_en, &temp, &i, &do_this);
	if (attr->spec == 'f' || attr->spec == 'F')
		ft_putstr_float(res_en);
	fourth_helper_for_presicion_e(&drob, attr, &do_this, temp);
	free(temp);
	return (func_for_return(attr, do_this));
}
