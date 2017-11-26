#include <stdlib.h>

void reset_map(char ***map, int size)
{
	int i;
	int j;

	i = 0;
	if (*map)
	{
		while(*map[i])
			free(map[i++]);
		free(*map);
		i = 0;
	}
	*map = (char**)malloc(sizeof(char*) * size + 1);
	while(i < size)
	{
		*map[i] = (char*)malloc(sizeof(char) * size + 1);
		j = 0;
		while (j < size)
			*map[i][j++] = '.';
		*map[i][j] = '\0';
		i++;
	}
	*map[size] = 0;
}
