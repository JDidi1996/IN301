#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct element{ 
	int val;
	struct element *suiv;
};
typedef struct element *liste;

struct element2{
	liste val;
	struct element2 *suiv;
};
typedef struct element2 *lliste;

int somme(liste l)
{
	if (l == NULL) return 0;
	else 		   return l->val + somme(l->suiv);
}

int occurence(liste l, int e)
{
	if (l == NULL) return 0;
	if (l->val == e) return 1 + occurence(l->suiv,e);
	else return occurence(l->suiv, e);
}



liste supprimer(liste l, int e)
{
	liste tmp,p;
	p = l;
	
	if ( l == NULL) return p;
	if ( l->val == e)
	{
		tmp = l->suiv;
		free(l);
		l = tmp;
		l = supprimer(l,e);
		
	}
	else
	l->suiv = supprimer(l->suiv, e);
	return p;
}



void afficheListe(liste l)
{
while ( l != NULL)
	{
		printf(" %d ->",l->val); // affiche : |le numero de la requete| priorité de la requete|
		l = l->suiv;
	}
	printf(" NULL \n");	
}

int valMax(liste l)
{
	int n;
	if ( l == NULL) return 0;
	n = valMax(l->suiv);
	if ( n < l->val) return n;
	else return l->val;
	
}

int main()
{
	int res;
	liste l = NULL;
	res = valMax(l);
	printf("%d", res);

	
	return 0;
}
