#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define N 10


double suite(double n, double i) // On part de i = 1 à i = n avec 1 <= n <= N
{
	double u;
	
	if ( i == n)
	{
		return sqrt(n);
	}
	return u = sqrt(  i + suite (n, i+1 ));
	
}


int main()
{

	double u;
	u = suite(1, 1);
	
	printf(" u = %f \n", u);
	
	return 0;
}
