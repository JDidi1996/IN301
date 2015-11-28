#include "graphics.h"

//## structure liste doublement chainée pour pouvoir revenir en arrière ##//
typedef struct element{
  PLATEAU plt;
  struct element *suiv;
  struct element *prec;
}*Liste;

typedef struct listeP{
	Liste debut;
	Liste fin;
}ListeP;

//## Gestion liste doublement chainée pour les retours en arrières ##//

ListeP init_liste(ListeP *l)
{
	l->debut = NULL;
	l->fin = NULL;
	return *l;
}

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

int tailleListe(ListeP l)
{
	if ( l.debut == NULL) return 0;
	else return 1+ tailleListe(l.debut->suiv);
}
