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

void InsererElement( int *T, int elem) // On insere un élément d'un tableau trié
{
	int i;
	
	// Décalage du tableau 
	
	for ( i = 0; i < N; i++)
	{
		if ( elem < *(T+i) ) 
			{
				decalage( T, i ); break;
			}
	}
	
	// Insertion de l'élément
	
	*(T+i) = elem;
	
	
}

void Inverse ( int *T ) // Inverse les éléments du tableau
{
	int i,tmp;
	
	for ( i = 0; i < N/2; i++)
	{
		tmp = *(T+i);
		*(T+i) = *(T+(N-1)-i);
		*(T+(N-1)-i) = tmp;		
	}

}

void Double_Neg( int *T) // Supprime les valeurs double ( ou plus) positives en remplaçant par leur valeur négative
{
	int i, j;
	
	for ( i = 0; i < N; i++)
	{
		for ( j = 0; j < N; j++)
			{
				if ( (*(T+i) == *(T+j)) && (*(T+i) >= 0) && (i != j) ) *(T+j) = - *(T+j); 
			}
	}
	
}

int Moyenne_Section(int *T) // Calcul la moyenne des produits de chaque section
{
	int m, s; // S = nombre de section
	int mtmp; //m temporaire
	int i;
	s = 1;
	m = 0;
	mtmp = 1;
	
	for ( i = 0; i < N; i++) // Avec T[0] != 0
	{
		if ( (*(T+i) == 0) && (*(T+i-1) != 0 ) ) 
		{
			s++;
			m = m + mtmp;
			mtmp = 1;
		}
		else 
		{
			mtmp = mtmp*(*(T+i));
		}
	}
	
	m = m/s;
	
	return m;
}

int main()
{
	int i;
	int T[N];
	
	init_case(T);
	
	T[4] = 4;
	T[5] = 0;
	
	for ( i = 0; i < N; i++)
	{
		printf("Le produit des éléments du tableau est : %d \n", T[i]); 
	}
	
	InsererElement(T,5); 
	Double_Neg(T);
	
	for ( i = 0; i < N; i++)
	{
		printf("%d \n", T[i]); 
	}
	
	printf("La moyenne des sections est %d \n", Moyenne_Section(T));
	
	
	
	
	
}
