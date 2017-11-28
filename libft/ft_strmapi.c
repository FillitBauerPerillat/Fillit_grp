/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:00:35 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/12 12:07:15 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t i;
	char *str;

	i = -1;
	str = (char*)malloc(sizeof(*s) * ft_strlen(s));
	if (str == NULL)
		return (NULL);
	while (s[++i])
		str[i] = (*f)((unsigned int)i, s[i]);
	return (str);
}
