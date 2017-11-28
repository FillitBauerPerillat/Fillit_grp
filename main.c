/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:48:41 by gperilla          #+#    #+#             */
/*   Updated: 2017/11/27 15:33:34 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"

int main(int argc, char** argv)
{
	int i;

	argc = 0;
	t_env env;
	printf("%d\n",ctoi_l_error(argv));
	faites_place(&env, argv);
	printf("%s\n", env.tetri[0]);
	printf("%d\n", c_pas_zelda(env.tetri));
	ds_to_alpha(&env);
	
	resolve(&env);
	show_result(env.map);
	return 0;
}
