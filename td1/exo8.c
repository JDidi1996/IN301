#include "stdio.h"


int main()
{
	
	int u; 
	int i; // entier qui va compter le nombre d'itération
	
	u = 34; // On affecte à u la valeur de départ u0
	i = 0;
	
	while ( u != 1 )
	{
		u = ( u%2 == 0 ? u/2 : 3*u + 1 );
		printf(" u = %d \n", u);
		i = i +1;
		
	}
	printf(" Il y a eu %d itérations \n \n", i);
	
	printf(" Deuxième partie du programe: \n");
	
	int NMAX;
	int valU; // Valeur U de départ
	NMAX = 19;
	
	valU = 1;
	while ( valU <= NMAX )
	{
		i = 0; 
		u = valU; // On affecte à u la valeur de départ
		while ( u != 1 )
		{
			u = ( u%2 == 0 ? u/2 : 3*u + 1 );
			i = i +1; // rajoute 1 au compteur d'itération
		
		}
	printf(" Il y a eu %d itérations pour u = %d \n", i, valU);
	valU = valU +1; // On rajoute 1 à la valeur de départ
	
	}	
	
}
