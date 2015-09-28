#include "stdio.h"

int factorielle (int n)
{
	int f;
	
	while ( n > 0)
	{
	if ( n <= 1 )
		f = 1;
	else
		f = n * factorielle(n--);
		
	}
	
	return f;
}

/* 
  La fonction donne des résultat faux car elle ne revoie rien.
 
*/
	
int main()
{
	
	int a;
	a = 4;
	
	printf( " le factorielle de %d est %d \n", a, factorielle(a));
}
