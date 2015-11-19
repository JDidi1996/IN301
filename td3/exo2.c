#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element
{
	char val;
	struct Element* suiv;
};
typedef struct Element* ListeC;

ListeC ajout_debut(ListeC l, char e)
{
	ListeC p;
	p = malloc(sizeof(struct Element));
	
	p->val = e;
	p->suiv = l;
	
	return p;
}

ListeC ajout_fin(ListeC l, char e)
{
	if ( l == NULL ) //Si l est vide on ne parcours pas la liste on ajoute e au debut;
	{
		l = ajout_debut(l,e);
		return l;
	}
	
		l->suiv = ajout_fin(l->suiv,e);
		return l;
}

void afficheChaine( ListeC l)
{
	while ( l != NULL)
	{
		printf("%c ", l->val);
		l = l->suiv;
	}
	printf("\n");
	
}

ListeC ajoutChaine(char* t, ListeC l)
{
	 if ( t[0] == '\0') return l;
	 else{
	 l = ajout_fin(l, t[0]);
	 l = ajoutChaine(t+1, l);}	 
}

void remplitMot(char** argv, int argc, char** t, ListeC* l)
{
	int i = 0;
	while ( i < argc)
	{
		if ( argc == 0)
		{
			int c = 0;
			while( t == '\0')
			{
			c++;
			t = argv[0][i];
			
			}
		}
		else 
		{
			*l = ajoutChaine( argv[1], *l);
		}
		
	i++;	
	}
}

int main( int argc, char** argv)
{
	
	ListeC l;
	char *t;
	
	remplitMot(argv, argc, &t, &l);
	afficheChaine(l);

	
	
	
return 0;	
}
