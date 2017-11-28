#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 0;
	result = 0;
	while ((unsigned char)nptr[i] <= 32)
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	if (sign == -1)
		return (-result);
	else
		return (result);
}
