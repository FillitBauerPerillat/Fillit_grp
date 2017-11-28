/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:43:03 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/13 19:02:20 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if(s1 == 0 || s2 == 0)
		return (0);
	while (((int)s1[i] == (int)s2[i] && s1[i] != '\0') && (i < n))
		i++;
	if (i == ft_strlen(s1) && i == ft_strlen(s2))
		return (1);
	return (0);
}
