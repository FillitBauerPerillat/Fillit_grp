/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:35:04 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/27 11:51:53 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int	ft_sqrt(int nb)
{
	int n;

	n = 1;
	if (nb == 1)
		return (1);
	if (nb >= 2)
	{
		while ((n * n < nb))
		{
			n++;
		}
		if (nb % n == 0)
			return (n);
	}
	return (0);
}

int			size_map(int n)
{
	int cpt;

	if (n <= 0)
		return (0);
	while (!ft_sqrt(n))
		n++;
	cpt = ft_sqrt(n) * 2;
	return (cpt);
}
