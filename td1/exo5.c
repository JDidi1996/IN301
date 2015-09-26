#include "stdio.h"


int i; 
int test(int n)	// Test si un nombre est premier ou non
{
	for ( i = 2; i < n; i++ )
	{
		if ( (n%i) == 0 )
		{
			return 1;
		}
			
	}
	return 0;
}

int main()
{
	int n ; // n = entier à tester
	n = 98;
	
	if ( test(n) == 1)
	printf( " %d n'est pas un nombre premier car il est divisible par %d \n", n, i);
	else
	printf( " %d est un nombre premier \n", n);
}
