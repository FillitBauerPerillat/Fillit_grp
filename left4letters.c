#include "fillit.h"

void	ds_to_alpha(t_env *env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (env->tetri[i])
	{
		j = 0;
		while (env->tetri[i][j])
		{
			if (env->tetri[i][j] == '#')
				env->tetri[i][j] = 'A' + i;
			j++;
		}
		i++;
	}
}

int	check_pos(int x, int y,char *piece, char **map)
{
	int iy;
	int jx;
	int flag;
	int gx;
	int gy;

	iy = 0;
	flag = 0;
	while (iy < 5)
	{
		jx = 0;
		while (jx < 5)
		{
			if (piece[iy * 5 + jx] != '.')
			{
				if (!flag)
				{
					gy = iy;
					gx = jx;
					flag = 1;
				}
				if (map[y + (iy - gy)][x + (jx - gx)] != '.')
					return (0);
			}
			jx++;
		}
		iy++;
	}
	return (1);
}





static void	deplace(char **str, int c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '#')
			{
				str[i][j - c] = '#';
				str[i][j] = '.';
			}
			j++;
		}
		i++;
	}
	for (int i = 0; str[i]; i++)
		printf("%s", str[i]);

}

void	on_est_de_gauche_ici(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j + 1] == '#' || (j < 17 && str[i][j + 5] == '#')) && str[i][j] == '#' && str[i][0] != '#')
			{
				deplace(str, j);
				break;
			}
			else if (str[i][j] == '#' && (j < 19 && str[i][j + 3] == '#')  && str[i][2] != '#')
			{
				deplace(str, (j - 2));
				break;
			}
			else if (str[i][j] == '#' && (( j < 18 && str[i][j + 4] == '#') || (j < 12 && str[i][j + 9] == '#')) && str[i][1] != '#')
			{
				deplace(str, j - 1);
				break;
			}
			j++;
		}
		i++;
	}
}
