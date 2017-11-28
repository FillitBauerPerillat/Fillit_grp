/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:00:30 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/13 18:49:49 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;
	size_t		i;

	pdest = dest;
	psrc = src;
	i = 0;
	if ((int)pdest >= (int)psrc)
		ft_memcpy(dest, src, n);
	else
	{
		psrc = psrc + n - 1;
		pdest = pdest + n - 1;
		while (i <= n)
		{
			pdest[n] = psrc[n];
			n--;
		}
	}
	return (dest);
}
