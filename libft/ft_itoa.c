/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:40:24 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/15 18:03:02 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		neg(intmax_t *n, int *negative, intmax_t *temp, size_t i)
{
	if (*n < 0)
	{
		*negative = 1;
		*n *= -1;
	}
	if (*negative == 1 || *n == 0)
		i++;
	while (*temp != 0)
	{
		*temp /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(intmax_t n)
{
	char		*array;
	size_t		i;
	int			negative;
	intmax_t	temp;

	i = 0;
	temp = n;
	negative = 0;
	i = neg(&n, &negative, &temp, i);
	array = (char *)malloc(sizeof(char) * i + 1);
	if (array == NULL)
		return (NULL);
	array[i] = '\0';
	while (i-- != 0)
	{
		array[i] = n % 10 + '0';
		n /= 10;
	}
	if (negative == 1)
		array[0] = '-';
	return (array);
}
