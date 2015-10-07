#include "stdio.h"


int somme(int n)
{
	int i;
	int s;
	s = 0;
	
	for ( i = 1; i < n; i++ )
	{
		if ( (n%i) == 0 )
		{
			s = s + i;
		}
			
	}
	return s;
}

int amis(int n, int m)
{
	int sn, sm; //somme des div de n et somme des div de m
	int i;
	sn = somme(n);// Somme de tout les diviseurs de n sauf lui meme
	sm = somme(m);// Somme de tout les diviseurs de m sauf lui meme

	if ( (sn == m) && (sm == n) ) {return 1;}
	else 			return 0;
}

void couple_amis(int nmax)
{
	int i, j;
	
	for (i = 0; i <= nmax; i++)
	{
		for (j = i; j <= nmax; j++)
		{
			if ( amis( i, j) == 1 ) printf(" %d et %d sont amis \n", i, j); // i = n, et j = m avec n <= m <= nmax
		}
	}
	
	
}

int main()
{
	
	couple_amis(3300);
	
	
}
