/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:57:37 by asusan            #+#    #+#             */
/*   Updated: 2019/08/06 18:57:39 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		func_for_return(t_att *attr, int do_this)
{
	if (attr->spec == 'e' || attr->spec == 'E')
		return (do_this + 4);
	else
		return (do_this);
}

void	install_fu(int *i, int *do_this, char **temp)
{
	*i = 0;
	*do_this = 0;
	*temp = NULL;
}

void	out_sign(int sign, t_att *attr)
{
	if (sign > 0)
		ft_putchar('-');
	else if (attr->flag[2] == '+')
		ft_putchar('+');
	else if (attr->flag[4] == ' ')
		ft_putchar(' ');
}

void	give_me_value_for_drob(char **drob)
{
	while (**drob != '.' && **drob != '\0')
		++(*drob);
	(*drob)++;
}

int		bonus_for_second_helper(t_att *attr, char **res_en, int do_this)
{
	if (attr->spec == 'e' || attr->spec == 'E')
		(position(*res_en) > 0) ? (do_this += 1) : (do_this = 2);
	else if (attr->spec == 'f' || attr->spec == 'F')
		(position(*res_en) > 0) ? (do_this +=
				bonus_func_vc_position(*res_en)) : (do_this = 2);
	return (do_this);
}
