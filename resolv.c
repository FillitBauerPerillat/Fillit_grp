/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:05:36 by gperilla          #+#    #+#             */
/*   Updated: 2017/11/27 14:36:25 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	place_piece(int x, int y, char *piece, char **map)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (piece[i] != '.' && piece[i] != '\n')
			map[x + (i % 5)][y + (i / 5)] = piece[i];
		i++;
	}
}

static void	remove_piece(int x, int y, char *piece, char **map)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (piece[i] != '.' && piece[i] != '\n')
			map[x + (i % 5)][y + (i / 5)] = '.';
		i++;
	}
}

static int	next_piece(t_env env, int size, int nb_piece)
{
	int x;
	int y;

	if (nb_piece == env.tetri_nbr)
		return (1);
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (check_pos(x, y, env.tetri[0], env.map))
			{
				place_piece(x, y, env.tetri[0], env.map);
				if (next_piece(env, size, (nb_piece + 1)))
					return (1);
				remove_piece(x, y, env.tetri[0], env.map);
			}
			++y;
		}
		++x;
	}
	return (0);
}

int			resolve(t_env env)
{
	int solved;
	int size;

	size = size_map(env.tetri_nbr);
	solved = 0;

	while (!solved)
	{
		reset_map(&env.map, size);
		solved = next_piece(env, size, 0);
		size++;
	}
	return (1);
}
