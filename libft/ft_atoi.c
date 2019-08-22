/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 03:57:52 by fgeruss           #+#    #+#             */
/*   Updated: 2019/04/23 11:19:43 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	size_t		i;
	int			neg;
	long int	n;

	i = 0;
	neg = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	neg = str[i] == '-' ? -1 : 1;
	if (neg == -1)
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + ((str[i] - '0') * neg);
		i++;
		if (n > 0 && neg < 0)
			return (0);
		else if (n < 0 && neg > 0)
			return (-1);
	}
	return (n);
}

long long int	ft_atoi_for_f(const char *str)
{
	size_t			i;
	int				neg;
	long long int	n;

	i = 0;
	neg = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	neg = str[i] == '-' ? -1 : 1;
	if (neg == -1)
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + ((str[i] - '0') * neg);
		i++;
		if (n > 0 && neg < 0)
			return (0);
		else if (n < 0 && neg > 0)
			return (-1);
	}
	return (n);
}
