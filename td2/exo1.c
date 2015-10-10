#include <stdio.h>

void echange(int* a, int* b)
{
	int tmp;
	
	tmp =  *a;
	*a = *b;
	*b = tmp;
	
}

	// Question c)

void reinitPointeur( int** p) // ** pointe l'adresse d'un pointeur
{	
	*p = NULL;
} // La fonction suivante réinitialise l'adresse d'un pointeur à NULL.


int main() 
{
	unsigned long int a;
	char tab[10];
	
	// Question a
	printf("Question A: \n \n");
	
	a = sizeof(char);
	printf("sizeof(char) = %lu \n",a); // Le plus petit type et pred donc 1 octet
	
	a = sizeof(int);
	printf("sizeof(int) = %lu \n",a); // 4 octets ou 32 bits
	
	a = sizeof(double);
	printf("sizeof(double) = %lu \n",a); // Un double est plus precis qu'un float donc prend plus de mémoire qu'un float. 
	
	a = sizeof(float);
	printf("sizeof(float) = %lu \n",a); // Tout les void*, char*,int*,.... sont de taille 4 car se sont des adresses. 
										// Ici c'est de 4 octets car je marche sur un systeme 32 bits.
	a = sizeof(char*);
	printf("sizeof(char*) = %lu \n",a);
	
	a = sizeof(void*);
	printf("sizeof(void*) = %lu \n", a);
	
	a = sizeof(int*);
	printf("sizeof(int*) = %lu \n",a);
	
	a = sizeof(double*);
	printf("sizeof(double*) = %lu \n",a);
	
	a = sizeof(int**);
	printf("sizeof(int**) = %lu \n",a);
	
	a = sizeof(int[10]);
	printf("sizeof(int[10]) = %lu \n",a);
	
	a = sizeof(char[7][3]);
	printf("sizeof(char[7][3]) = %lu \n \n",a);
	
/*	a = sizeof(int[]);
	printf("sizeof(int[]) = %lu \n",a); // Erreur:  Ne ne fonctionne pas quand on ne définie pas la taille du tableau */
	
	
	
	
	a = sizeof(tab);
	printf("sizeof(tab) = %lu \n",a); // Tableau de 10 caractère
	
	a = sizeof(tab[0]);
	printf("sizeof(tab[0]) = %lu \n",a); // 1 seul caractère donc taille 1
	
	a = sizeof(&tab[0]);
	printf("sizeof(&tab[0]) = %lu \n",a); // car c'est l'adresse du tableau.
	
	a = sizeof(*&tab);
	printf("sizeof(*&tab) = %lu \n",a); // Pointe la valeur de l'adresse du tableau : Donc 10 caracère de taille 1
	
	a = sizeof(*&tab[0]);
	printf("sizeof(*&tab[0]) = %lu \n \n",a); // Pointe la valeur de l'adresse du tableau : Donc 1 car c'est 1 seul caractère.
	
	char (*p)[10] = &tab; // C'est un pointeur sur un tableau de caractère ( l'adresse d'un tableaud e 10 caractères)
	
	a = sizeof(p);
	printf("sizeof(p) = %lu \n",a);
	
	a = sizeof(*p);
	printf("sizeof(*p) = %lu \n",a); // revoie ce qu'il y a à l'adresse de p
	
	a = sizeof((*p)[2]);
	printf("sizeof((*p)[2]) = %lu \n",a);
		
	a = sizeof(&(*p)[2]);
	printf("sizeof(&(*p)[2]) = %lu \n \n",a); 
	
	

	
	// Question b)
	
	printf("Question B: \n \n");
	
	int c;
	int b;
	c = 2; b = 3;
	
	printf(" c = %d et b = %d \n", c, b);
	
	echange( &c, &b);
	printf(" c = %d et b = %d \n \n", c, b);
	
	
	// Question c)
	
	printf("Question C: \n \n");
	
	int d = 1; 
	int* q = &d;
	printf(" q = %p \n ", q);
	reinitPointeur(&q);
	printf(" q = %p \n", q);
	


	return 0;	
}
