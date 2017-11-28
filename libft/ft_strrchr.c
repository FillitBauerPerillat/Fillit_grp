#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	pc;
	int				i;
	int				len;
	char			*ps;

	pc = c;
	i = 0;
	len = ft_strlen(s);
	ps = (char*)s;
	while (len >= 0)
	{
		if (ps[len] == pc)
			return (&ps[len]);
		len--;
	}
	return (NULL);
}
