#include "stdio.h"

int main()
{
	
	float i, S, Sn;
	double p; //precision

	Sn = 1; 
	S = 0;
	p = 0.01;
	i = 1;	
	
	while (  (Sn-S) > p )
	{
		i++ ;
		S = Sn;
		Sn = Sn + (1/(i*i));
		
	}
	
	printf(" La limite de la suite Sn est %f",Sn);

return 0;	
}
