/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:21:45 by fgeruss           #+#    #+#             */
/*   Updated: 2019/08/22 16:20:39 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "../includes/libft.h"
# include <stdio.h>
# include <stdarg.h>

/*
** Specificators: d, u, p, x, X, o, e, E, f, s, c, u, %
** Flags: -, +, #, 0, ' '
** Width: *, (num)
** Precision: .(num), .*
** Length: (none), hh, h, l, ll, j, z, t, L
*/

typedef struct				s_att
{
	char					flag[6];
	long long int			width;
	long long int			prec;
	char					spec;
	char					length;
}							t_att;

/*
** Структура и объединение для %f
*/

typedef struct				s_float
{
	unsigned long long int	mantisa : 64;
	unsigned int			exponent : 15;
	short int				sign : 1;
}							t_float;

typedef union				u_float_u
{
	long double				f;
	t_float					bytes;
}							t_float_u;

int							ft_printf(const char *format, ...);
int							length(char *format);
int							opr_len(char *temp, t_att *att);
int							opr_flag(char **format, t_att *att);
int							opr_width(char *format, t_att *w, va_list ap);
void						opr_spec(char *format, t_att *fl, int length);
int							precision(char *temp, t_att *p, va_list ap);
int							printing(va_list ap, t_att *attr);
int							check_flag(char a[], char c);
int							print_split(t_att *attr, int size, char *str);
int							print_another(t_att *attr);
int							len(char c);
void						initialize(t_att *att);
int							print_split_first(t_att *attr, int size, char *str);

/*
** Печать спецификаторов
*/

int							print_d(va_list ap, t_att *attr);
int							print_c(va_list ap, t_att *attr);
int							print_s(va_list ap, t_att *attr);
int							print_o(va_list ap, t_att *attr);
int							print_x(va_list ap, t_att *attr);
int							print_u(va_list ap, t_att *attr);
int							print_e(va_list ap, t_att *attr);

/*
** Печатают нули
** пробелы и др
*/

int							print_splits(int space);
int							print_zero(unsigned long int zero);
int							digits_nbr(intmax_t nbr);
void						ft_putunbr(uintmax_t nbr);
int							get_zero(t_att *a, int *len, int sign);
int							get_space(t_att *a, int *len);
void						print_sign(intmax_t nbr, t_att *a);
int							print_zero_for_slash(uintmax_t nbr, t_att *a);

int							helper_for_presicion_1(t_att *attr,
		char **temp, char **res_en, int *i);
int							helper_for_presicion_2(char **temp,
		char **res_en, char **drob, int *i);
int							helper_for_presicion_3(char **res_en,
		char **temp, int *i);
int							helper_for_presicion_4(char **res_en,
		char **temp, int *i, int *do_this);
int							helper_for_presicion_5(t_att *attr,
		int *do_this, int i, int sign);
void						out_sign(int sign, t_att *attr);
int							func_for_return(t_att *attr, int do_this);
void						install_fu(int *i, int *do_this, char **temp);
void						give_me_value_for_drob(char **drob);
int							bonus_for_second_helper(t_att *attr,
		char **res_en, int do_this);
int							bonus_for_first_helper(char *perem,
		t_att *attr, char **drob);
void						sum_1(char **drob, t_att *attr,
		char **res_en, char *perem);
char						*for_nan_inf(t_att *attr, int chooose,
		long double nbr);
int							give_me_true_presicion_e(char *drob,
		t_att *attr, char *res_en);
char						*sum_for_e(char *exp_five, char *sum_one, int size);
void						installer(int *power, char **drob,
		char **entire, int k);
void						for_norminette(int *do_this,
		t_att *attr, int spec_e);
void						for_norminette_1(int i, int *do_this, t_att *attr);
void						for_norminette_2(int i, int *do_this, t_att *attr);
void						for_norminette_3(char **res_en,
		char **drob, char **temp);
void						for_norminette_4(char **drob, char **res_en);
void						ft_print_for_e(char **res_en, int *i);
void						help_for_opr_len(char *temp, int count, t_att *a);
void						help_for_opr_len_1(char *temp, int count, t_att *a);

/*
** %f
*/

int							ft_putstr_float(char *str);
char						*sum(char *exp_five, char *sum_one, int size);
char						*mult_two(int power, int k, char *res);
char						*mult_five(int power, int k,
		char *res, int max_power);
int							position(char *arr);
int							find_max_power(char *arr);
int							bonus_func_vc_position(char *arr);
int							find_next_value(char *drob, t_att *attr);

int							func_for_output_nan(t_att *attr, char *arr);

#endif
