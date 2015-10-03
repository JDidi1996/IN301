#include "stdio.h"

int main()
{
	
	double i, s;
	double p; //precision

	s = 1; // Sn
	p = 0,001;
		
	i = 1;	
	while (  (1/(i*i)) >	 p )
	{
		i++ ;
		s = s + (1/(i*i));
		
	}
	
	printf(" La limite de la suite Sn est %f",s);
	
}
