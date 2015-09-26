#include "stdio.h"

int factorielle (int n)
{
	int f;
	
	while ( n > 0)
	{
	if (n <= -1)
		f = 1;
	else
		f = n * factorielle(--n);
	}
	return f;
}

/* 
 La fonction suivante ne peut marcher car elle tourne en boucle jusqu'à n = 0
 
 
*/
	
int main()
{
	
	int n;
	int fact;
	n = 6;
	
	fact = factorielle(n);
	printf( " le factorielle de %d est %d \n", n, fact);
}
