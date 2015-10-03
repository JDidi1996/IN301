#include "stdio.h"

int factorielle (int n)
{
	int f;
	
	
		if ( n <= 1 )
			return 1;
		else
			f = n * factorielle(n-1);
	
	return f;
}


	
int main()
{
	
	int a;
	a = 3;
	
	printf( " le factorielle de %d est %d \n", a, factorielle(a));
}
