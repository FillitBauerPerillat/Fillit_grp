/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:47:10 by gperilla          #+#    #+#             */
/*   Updated: 2017/11/16 16:03:54 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

static void	copier_c_mal(char **dst, char *src, int nb)
{
	int		fd;
	int		i;
	char	buff[22];

	fd = open(src, O_RDONLY);
	i = 0;
	while (i < nb)
	{
		ft_memset(buff, '\n', 21);
		buff[21] = '\0';
		if (!read(fd, buff, 21))
			return ;
		ft_strcpy(dst[i], buff);
		i++;
	}
}

char		**faites_place(char **av)
{
	int		cpt;
	int		fd;
	char	**tetri;
	char	buff[1];

	if (av == NULL)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	while (read(fd, buff, 1))
		if (buff[0] == '\n')
			cpt++;
	close(fd);
	cpt = (cpt / 5);
	tetri = (char**)malloc(sizeof(char*) * cpt + 1);
	fd = 0;
	while (fd < cpt)
		tetri[fd++] = (char*)malloc(sizeof(char) * 22);
	tetri[cpt] = 0;
	copier_c_mal(tetri, av[1], cpt);
	return (tetri);
}
