/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:14:44 by asusan            #+#    #+#             */
/*   Updated: 2019/04/19 23:07:52 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	ptr = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		ptr[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
