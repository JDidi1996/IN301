#include "stdio.h"
int n,m;

int somme_n()
{
	int i;
	int sn;
	for ( i = 1; i < n; i++ )
	{
		if ( (n%i) == 0 )
		{
			sn = sn + i;
			printf( "Sn = %d \n",sn);
		}
			
	}
	return sn;
}

int somme_m()
{
	int i;
	int sm;
		for ( i = 1; i < m; i++ )
	{
		if ( (m%i) == 0 )
		{
			sm = sm + i;
			printf( "Sm = %d \n",sm);
		}
			
	}
	
	return sm;
}

int amis(int n, int m)
{
	int sn, sm; //somme des div de n et somme des div de m
	int i;
	sn = 0;
	sm = 0;
	
	

	if ( sn == sm ) {return 1;}
	else 			return 0;
}

int main()
{
	
	n = 220; 
	m = 284;
	
	if ( amis(n, m) == 1) printf("Les entier m et n sont dits amis \n");
	else 				  printf("Les entier m et n ne sont pas dits amis \n");
	
	
}
