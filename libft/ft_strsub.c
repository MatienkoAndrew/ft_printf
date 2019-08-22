/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:55:22 by fgeruss           #+#    #+#             */
/*   Updated: 2019/04/11 19:47:20 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (array == NULL)
		return (NULL);
	while (len--)
	{
		array[i] = s[start + i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
