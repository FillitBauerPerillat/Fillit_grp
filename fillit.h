/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:49:45 by gperilla          #+#    #+#             */
/*   Updated: 2017/11/27 15:07:41 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_env
{
	char **tetri;
	int tetri_nbr;
	char **map;
}				t_env;

void	faites_place(t_env *env, char **av);

int		ctoi_l_error(char **av);

int		c_pas_zelda(char **tetri);

void	ds_to_alpha(t_env *env);

void	ft_error(char *str);

int		check_pos(int x, int y,char *piece, char **map);

void	reset_map(char ***map, int size);

int		size_map(int n);

#endif
