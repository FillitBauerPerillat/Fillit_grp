/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:48:41 by gperilla          #+#    #+#             */
/*   Updated: 2017/11/16 15:30:26 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"

int main(int argc, char**argv)
{
	char **tetri;

	if (!ctoi_l_error(argv))
		c_foutu();
	tetri = faites_place(argv);
	if (!c_pas_zelda(tetri))
		c_foutu();
	for (int i = 0; tetri[i]; i++)
		printf("%s", tetri[i]);
	return 0;
}
