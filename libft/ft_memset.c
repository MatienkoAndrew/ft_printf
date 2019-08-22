/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:01:53 by fgeruss           #+#    #+#             */
/*   Updated: 2019/04/05 19:07:05 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (destination);
	while (i < n)
	{
		((unsigned char *)destination)[i] = (unsigned char)c;
		i++;
	}
	return (destination);
}
