#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Pascale(int n, int p)
{
	if ( (p == 0) || (p == n) ) return 1;
	else return Pascale(n-1, p) + Pascale(n-1, p-1);
}

int pivot( int* tab, int g, int d)
{
	int m;
	m = (g+d)/2;
	
	if ((tab[m] <= tab[m+1]))  pivot ( tab, m+1,d);
	else  pivot ( tab, g,m);
}

int controle(double n)
{
	int x;
	double i, j;
	
	x = 0;
	for ( i = 0; i <= n ; i++)
	{
	j = pow(2,i);
	printf("j = %f", j);
	while ( j <= pow(2,n-i))
		{
			j = j+1;
			x = x+1;
			
		}	
	}
	return x;
	
}


int main()
{
 
int res;

res = controle(2);
printf("res = %d",res);

return 0;
}
