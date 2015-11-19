#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	printf(" NULL");
	printf(" \n");
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

liste supprime2(liste l, int e)
{
	liste p, tmp;
	p = l;
	
	if ( l == NULL) return l;
	while ( (l != NULL) && (l->suiv != NULL))
	{
		if ( l->suiv->val == e)
		{
			tmp = l->suiv->suiv;
			free(l->suiv);
			l = tmp;
		}
		else
		l = l->suiv;
	}
	return p;
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

liste alea_liste( int n)
{
		int x;
		liste l = init_liste();
		
		srand(time(0));
		while (1)
		{
			x = rand()%n;
			if ( x == 0) return l;
			else l = ajout_debut(l, x);
			
		}
		return l;
}

liste entrelacer(liste l1, liste l2) // Entrelacement de deux tableaux triées
{
	liste l3,l4;
	
	if ( l1 == NULL ) return l2;
	if ( l2 == NULL ) return l1;
	
	if ( l1->val < l2->val)
		{
			l3 = l1;
			l1 = l1->suiv;
		}
		else
		{
			l3 = l2;
			l2 = l2->suiv;
		}
	
	l4 = l3;
	
	while( (l1 != NULL) && (l2 != NULL) )
	{
		if ( l1->val < l2->val)
		{
			l3->suiv = l1;
			l3 = l3->suiv;
			l1 = l1->suiv;
			affiche_liste(l4);
		}
		else
		{
			
			l3->suiv = l2;
			l3 = l3->suiv;
			l2 = l2->suiv;
			affiche_liste(l4);
		}
	}
	
	if ( l2 == NULL)  l3->suiv = l1;
	if ( l1 == NULL)  l3->suiv = l2;
	
	return l4;
}

liste tri_liste_bulle(liste l)
{
	liste temp;
	int tp, compt;
	compt = 0;
	temp = l;
	
	if ( (l == NULL) || (l->suiv == NULL)) return l;
	
	while ( compt != nb_element(l))
	{
		temp = l;
		compt =  1;
		
		while ( (temp != NULL) && (temp->suiv != NULL))
		{
			if ( temp->suiv->val < temp->val)
			{
				tp = temp->suiv->val;
				temp->suiv->val = temp->val;
				temp->val = tp;
				
			}
			else compt += 1;
			temp = temp->suiv;
			
		}
	}
	
	return l;
}

liste renverse(liste l1)
{	
	liste l2;
	l2 = init_liste();
	
	if ( (l1 == NULL) || (l1->suiv == NULL)) return l1;
	
	while ( l1 != NULL)
	{
		l2 = ajout_debut(l2,l1->val);
		l1 = l1->suiv;
	}
	
	return l2;

}

int main()
{
	liste p;
	srand(time(0));
		
	p = init_liste();
	p = alea_liste(4);
	affiche_liste(p);		
	
	printf(" \n");
	
	p = supprime2(p,3);
	affiche_liste(p);

	
	return 0;
}
