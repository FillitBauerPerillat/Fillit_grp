/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:14:40 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/13 19:04:23 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	int		len;
	int		start;
	int		end;

	i = 0;
	len = ft_strlen(s);
	if ((s[i] != ' ' && s[i] != '\n' && s[i] != '\t') && (s[len] != ' ' &&
				s[len] != '\n' && s[len] != '\t'))
		return ((char*)s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	i = 0;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	end = len;
	str = (char*)malloc(sizeof(*s) * (end - start));
	if (str == NULL)
		return (NULL);
	str = ft_strsub(s, start, (end - start));
	return (str);
}
