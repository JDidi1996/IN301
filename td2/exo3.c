#include <stdio.h>
#include <stdlib.h>

struct Element
{
	int val;
	struct Element* suiv;
};
typedef struct Element Element; 

typedef Element* liste;

liste init_liste()// Création d'une liste vide
{
	return NULL;
}

int vide(liste l)
{
	if ( l == NULL ) return 1; // La liste est vide
					 return 0; // La liste n'est pas vide
	
}

void affiche_liste(liste l) // Affiche les valeurs de la liste
{
	while ( l != NULL)
	{
		printf(" %d ->",l->val);
		l = l->suiv;
	}
}

void liberer_memoire(liste l)
{
	while ( l != NULL)
	{
		free(l); 
		l = l->suiv;
	}
}

//### VERSION RECUSIVE DE LIBERE ###//

/*
 
void libere(liste l)
{
		if (!vide(l))
		{
		libere(l->suiv);
		free(l);
		}
} 

*/

liste ajout_debut(liste l, int e)
{
	liste p;
	p = malloc(sizeof(Element));
	
	p->val = e;
	p->suiv = l;
	
	return p;
}

liste ajout_fin(liste l, int e)
{
	if ( vide(l) ) //Si l est vide on ne parcours pas la liste on ajoute e au debut;
	{
		l = ajout_debut(l,e);
		return l;
	}
	
		l->suiv = ajout_fin(l->suiv,e);
		return l;
}

int est_trie(liste l)
{
	liste p;
	p = l;
	
	while ( p != NULL)
	{
		if ( (p->val) > (p->suiv->val)) return 0;
	}
	 
	return 1;
}

liste ajout_tri(liste l, int e) //ajout dans une liste trié 
{
	if ( l == NULL)
	{
		return ajout_debut(l,e);
	}
	if ( e < (l->val) )
	{
		l = ajout_debut(l,e);
		return l;
	}
		l->suiv = ajout_tri(l->suiv,e);
		return l;
}

int nb_element(liste l)
{
	int res;
	res = 0;
	
	if ( l == NULL) return 0;
	res = 1 + nb_element(l->suiv);	
	
	return res;
}

int recherche_elem(liste l, int e) // Indique si e est dans la liste (VRAI = 1 OU FAUX = 0)
{
	if ( l == NULL ) return 0;
	
	while (l != NULL)
	{
	if ( l->val == e) return 1;
	l = l->suiv;
	}
	return 0;
}

liste supprime(liste l, int e)
{
	if ( l == NULL) return l;
	if ( l->val == e) {l = l->suiv;}
	
	l->suiv = supprime(l->suiv,e);
	
	return l;
}

liste concat(liste l1, liste l2)
{
	liste l;
		
	if ( l1 == NULL ) return l2;
	if ( l2 == NULL ) return l1;
	
	l = l1;
	while(l1->suiv != NULL)
	{
		l1 = l1-> suiv;
	}
	l1->suiv = l2;
	
	return l;
}

liste entrelacer(liste l1, liste l2) // Entrelacement de deux tableaux triées
{
	liste l;
	
			
	if ( l1 == NULL ) return l2;
	if ( l2 == NULL ) return l1;
	
	while( (l1 != NULL) && (l2 != NULL) )
	{
		if ( l1->val < l2->val)
		{
			l->val = l1->val;
			l = l->suiv;
			l1 = l1->suiv;
		}
		else
		{
			l->val = l2->val;
			l = l->suiv;
			l2 = l2->suiv;
		}
	}
	
	if ( l2 == NULL) l->suiv = l1;
	if ( l1 == NULL) l->suiv = l2;
	return l;
}

int main()
{
	liste l, p, j;
	j = malloc(sizeof(Element));
	
	l = init_liste();
	l = ajout_fin(l, 1);
	l = ajout_fin(l, 3);
	l = ajout_fin(l, 5);
	l = ajout_tri(l, 0);
	affiche_liste(l);
	
	printf(" \n");
		
	p = init_liste();
	p = ajout_fin(p, 0);
	p = ajout_fin(p, 2);
	p = ajout_fin(p, 4);
	affiche_liste(p);		
	
	printf(" \n");
	
	j = entrelacer(l, p);
	affiche_liste(j);
	
	return 0;
}
