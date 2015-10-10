#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tableau 
{
	int taille;
	int tab[100];
} tableau;

int alea(int n)
{
	
	return rand() % n;
}

tableau init_tab(tableau T)
{
	int i;
	
	T.taille = 10;
	for (i = 0; i < T.taille; i++)
	{
			T.tab[i] = alea(20);
	}
	return T;
	
}

void affiche_tab(tableau T)
{
	int i;
	for (i = 0; i < T.taille; i++)
	{
			printf(" T.tab[%d] = %d \n", i, T.tab[i]);
	}
	
}

long long int produit(tableau T) // Affiche le produit des éléments du tableau
{
	int i;
	int produit = 1;
	for (i = 0; i < T.taille; i++)
	{
			produit = produit * T.tab[i];
	}
	return produit;
	
}

int minimun(tableau T) // Renvoie le minimun du tableau,
{
	int i, min;
	min = T.tab[0];
	for (i = 1; i < T.taille; i++)
	{
		if ( min > T.tab[i] ) min = T.tab[i];
	}
	return min;
	
}

tableau decalage(tableau T) // décalle tout les éléments d'une case vers la droite et affecte 0 à la case 0.
{
	int i;
	T.taille += 1;
	
	for (i = T.taille; i >0 ; i--)
	{
		T.tab[i] = T.tab[i-1];
	}
	T.tab[0] = 0;
	
	return T;
}

tableau Tri_tab(tableau T)// Tri le tableau
{
	int i, j, tmp;
	
	for (i = 0; i < T.taille ; i++)
	{
		for (j = 0; j < T.taille; j++)
		{
			if ( T.tab[i]  < T.tab[j] )
			{
			tmp = T.tab[i];
			T.tab[i] = T.tab[j];
			T.tab[j] = tmp;	
			}
		}
	}
	return T;
}
	
tableau Inserer(tableau T, int e) // Insere un élément dans un tableau trié (bug quand e > 20)
{
	int j, i;
	j = 0;
	
	
	while( e > T.tab[j])
	{
		j++;
	}
	
	for (i = T.taille; i >j ; i--)
	{
		T.tab[i] = T.tab[i-1];
	}
	T.taille = T.taille + 1;
	T.tab[j] = e;
	
	
	return T;
}

tableau Inverse(tableau T) // Inverse les éléments du tableau
{
	int i, tmp;
	
	for ( i = 0; i < (T.taille/2) ; i ++)
	{
		tmp =  T.tab[i];
		T.tab[i] = T.tab[T.taille -1 - i];
		T.tab[T.taille -1- i] = tmp;
	}

	return T;
}



int main()
{
	srand(time(NULL));
	
	printf("La taille mémoire du tableau est %d \n",sizeof(tableau)); 
	
	tableau T;
	
	T = init_tab(T);
	T = Tri_tab(T);
	affiche_tab(T); // Affichage du tableua après le tri
	
	printf("Le produit des éléments du tableau est %lld \n",produit(T)); 
	
	T = Inserer(T, 13);
	T = Inverse(T);
	affiche_tab(T); // Affichage du tableau après l'insertion de l'élément
	
	
	
	return 0;
}
