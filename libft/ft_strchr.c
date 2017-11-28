#include "libft.h"

char	*strchr(const char *s, int c)
{
	unsigned char	pc;
	char			*str;
	int				i;

	pc = c;
	str = (char*)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == pc)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
