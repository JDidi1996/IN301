#include "stdio.h"

#define N 10


void init_case(int *T) // Initialise les cases du tableau à 1;
{
	int i;
	
	for ( i = 0; i < N; i++)
	{
		*(T+i) = 1*i;
	}
	
}

int produit_tab(int *T) // Calcul et retourne le produit des éléments du tableau
{
	int produit;
	int i;
	produit = 1;
	
	for ( i = 0; i < N; i++)
	{
		produit = produit*(*(T+i));
	}
	 
	
	return produit;
	
}

int minimum( int *T) // Affiche le minimun d'un tableau
{
	int MIN, i;
	MIN = *T;
	
	for ( i = 0; i < N; i++)
	{
		if (MIN > *(T+i)) MIN = *(T+i);
	}
	 	
	return MIN;
}

void decalage( int *T, int n) // Décale tout les éléments de 1, avec n l'indice correspond au départ du décalage
{
	int i;
	
	for ( i = N-2; i >= n; i--) //On part de N-2 car on supprime le dernier élément du tableau
	{
		*(T+i+1) = *(T+i); 
	}	
}

void InsererElement( int *T, int elem)
{
	int i, tmp, MIN;
	
	
	// Triage du tableau
	
	for ( i = 0; i < N; i++) 
	{
		
	}	
	
	// Décalage du tableau 
	
	
	// Insertion de l'élément
}
	




int main()
{
	int i;
	int T[N];
	
	init_case(T);
	decalage(T, 3);
	for ( i = 0; i < N; i++)
	{
		printf("Le produit des éléments du tableau est : %d \n", T[i]); 
	}
	 
	
	
	
	
	
}
