#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *str;

	str = malloc(sizeof(str) * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
