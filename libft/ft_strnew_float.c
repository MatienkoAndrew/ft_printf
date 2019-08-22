/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:40:25 by fgeruss           #+#    #+#             */
/*   Updated: 2019/04/11 19:45:07 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_float(size_t size)
{
	char	*array;

	if (size + 1 == 0)
		return (NULL);
	array = (char *)malloc(sizeof(char) * size + 2);
	if (array == NULL)
		return (NULL);
	ft_memset(array, '0', size + 1);
	array[size + 1] = '\0';
	return (array);
}
