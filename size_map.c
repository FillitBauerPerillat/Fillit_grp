#include "fillit.h"
#include "libft.h"
#include "stdlib.h"

int	size_map(int n)
{
	int cpt;
	while (!ft_sqrt(n))
		n++;
	cpt = ft_sqrt(n) * 2;
	return (cpt);
}
