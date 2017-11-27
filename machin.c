



int nom(int nb)
{
	int unefoissurdeux = 0;
	int incr = 1;
	int cpt = 0;
	int ans = 2;

	while (nb--)
	{
		if (cpt == incr)
		{
			cpt = 0;
			ans++;
			if (unefoissurdeux++ == 1)
			{
				unefoissurdeux = 0;
				incr++;
			}
		}
		cpt++;
	}
	return (ans);
}

#include <stdio.h>

int main()
{
	for(int i = 1; i<25; i++)
		printf("%d\n", nom(i));
	return 0;
}
