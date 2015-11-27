#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"

typedef struct plateau
{
	int pos[17][17]; 			// tableau de taille 18x18 ( à expliquer plus tard pourquoi)
}PLATEAU; 	
 
typedef struct element{
  PLATEAU plt;
  struct element *suiv;
  struct element *prec;
}*Liste;

typedef struct listeP{
	Liste debut;
	Liste fin;
}ListeP;

ListeP init_liste(ListeP *l)
{
	l->debut = NULL;
	l->fin = NULL;
	return *l;
}

// On ajoute le plateau de jeu au début de la liste
// car cela prend moins de temps puis pour le retour en arrière 
// on supprime le plateau en debut de liste et on va sur la plateau 
// suivant qui correspond au tour précedent.
ListeP ajoutFin(ListeP l, PLATEAU P)		
{
	Liste a = malloc(sizeof(struct element));
	if ( l.debut == NULL)
	{
	l.debut->plt = P;
	l.debut->suiv = NULL;
	l.debut->prec = NULL;
	l.fin = l.debut;
	return l;
	
	}
	else
	{
	a->plt = P;
	a->suiv = NULL;
	a->prec = l.fin;
	l.fin = a;
	return l;
	}
}

ListeP supprimeFin(ListeP l)
{
	if (l.fin == NULL) return l;
	else
	{
		l.fin = l.fin->prec;
		l.fin->suiv = NULL;
		free(l.fin);
		return l;
	}
}

PLATEAU initPlateau()
{
	int i, j;
	PLATEAU P;
	
	for ( i = 0; i < 17; i++)
	{
		for ( j = 0; j < 17; j++)
		{
			if ( (i%2 == 0) && (j%2 == 0)) 
				P.pos[i][j] = 4;
			else 
				P.pos[i][j] = 0;
		}
	}
	return P;
}


int main()
{
	
	ListeP l;
	PLATEAU P;
	P = initPlateau();
	l = init_liste(&l);
	l = ajoutFin(l,P);
	
	
	
	return 0;
}
