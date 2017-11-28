/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:38:07 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/12 12:04:17 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t i;
	char *str;

	i = -1;
	str = (char*)malloc(sizeof(*s) * ft_strlen(s));
	if (str == NULL)
		return (NULL);
	while (s[++i])
		str[i] = (*f)(s[i]);
	return (str);
}
