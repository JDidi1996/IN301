#include "stdio.h"

int main()
{
	
	int n = 2;
	int i, som = 0;
	i = 1;
	
	while ( i < n)
	{
		som = som + 1/(i*i);
		i++;
		
		
	}
	
	printf(" La limite de la suite Sn est %d", som);
	
	
}
