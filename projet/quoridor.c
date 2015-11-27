#include "graphics.h"


enum direction {HAUT, BAS, DROIT, GAUCHE}; 
typedef enum direction Direction;

typedef struct plateau
{
	int pos[17][17]; 			// tableau de taille 18x18 ( à expliquer plus tard pourquoi)
}PLATEAU; 						// La case vaut 0 si il n'y a pas de mur, 1 si il y a un mur, 5 si il y n'a pas de pion  et 2 sinon.

PLATEAU P; 						// Declaration du plateau en variable globale

typedef struct joueur
{
	int i,j;				    // correspond aux indices de la case du plateau;
	int val;   		   			// valeur de la case du pion ( 2 pour J1, 3 pour J2)
	int mur;   			    	// Nb de murs qu'il reste au joueur
} JOUEUR;

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

//## Affichage des murs ##//
void afficheMur_h(int i, int j)
{
	POINT p1, p2;
	
	p1.x = 70*((i/2)+(i%2)); p2.x = 70*(((i/2)+(i%2))+1);
	p1.y = 70*((j/2)+(j%2))-1; p2.y = 70*((j/2)+(j%2)) -9;
	draw_fill_rectangle(p1,p2,rouge);
}

void afficheMur_v(int i, int j)
{
	POINT p1, p2;
	
	p1.x = 70*((i/2)+(i%2))-1; p2.x = 70*((i/2)+(i%2)) -9;
	p1.y = 70*((j/2)+(j%2)); p2.y = 70*((j/2)+(j%2) + 1);
	draw_fill_rectangle(p1,p2,rouge);
}

//## Affichage du plateau de jeu ##//
void affichePlateau(PLATEAU P)
{
	int i,j;
	POINT p1, p2;
	POINT p; // centre d'un pion
	
	for ( i = 0; i < 17; i++)
	{
		for ( j = 0; j < 17; j++)
		{
			if ( P.pos[i][j] == 4) //case n'ayant aucun pion
			{
				p1.x = 70*(i/2); p1.y = 70*(j/2) ;
				p2.x = 70*(i/2) + 60; p2.y = 70*(j/2) + 60;
				draw_fill_rectangle(p1, p2, blanc);
			}
			if ( P.pos[i][j] == 3) //Case ayant le pion de J2
			{
				p1.x = 70*(i/2); p1.y = 70*(j/2) ;
				p2.x = 70*(i/2) + 60; p2.y = 70*(j/2) + 60;
				draw_fill_rectangle(p1, p2, blanc);
				
				p.x = (p1.x + p2.x)/2;
				p.y = (p1.y + p2.y)/2;
				draw_fill_circle(p,25,bleu);
			}
			if ( P.pos[i][j] == 2) //Case ayant le pion de J1
			{
				p1.x = 70*(i/2); p1.y = 70*(j/2) ;
				p2.x = 70*(i/2) + 60; p2.y = 70*(j/2) + 60;
				draw_fill_rectangle(p1, p2, blanc);
				
				p.x = (p1.x + p2.x)/2;
				p.y = (p1.y + p2.y)/2;
				draw_fill_circle(p,25,vert);
			}
			if ( P.pos[i][j] == 1) //case ayant un mur 
			{
				if ( (i%2 == 0) && (j%2 == 1)) //cas mur horizontal
					afficheMur_h(i,j);
				if ( (i%2 == 1) && (j%2 == 0)) //cas mur vertical
					afficheMur_v(i,j);
			}
			if ( P.pos[i][j] == 0); //aucun mur (on ne fait rien)
			
						
		}
	}
}

//## Affiche les données ##//
void afficheData(JOUEUR J1, JOUEUR J2)
{
	POINT P, p1, p2;
	p1.x = 620; p1.y = 0;
	p2.x = WIDTH; p2.y = HEIGHT;
	draw_fill_rectangle(p1,p2,noir);
	
	P.x = 640; P.y = 600;
	aff_pol("MUR Joueur bleu : ", 18, P, bleu);
	P.x = 810; 
	aff_int(J2.mur, 18, P, bleu);

	P.x = 640; P.y = 150;
	aff_pol("MUR Joueur vert : ", 18, P, vert);
	P.x = 810; 
	aff_int(J1.mur, 18, P, vert);

}

//## initialisations des Joueurs ##//
JOUEUR init_joueur1()
{
	JOUEUR J1;
	J1.val = 2;
	J1.mur = 10;
	J1.i = 8;
	J1.j = 0;
	P.pos[J1.i][J1.j] = J1.val;

	return J1;
}

JOUEUR init_joueur2()
{
	JOUEUR J2;
	J2.val = 3;
	J2.mur = 10;
	J2.i = 8;
	J2.j = 16;
	P.pos[J2.i][J2.j] = J2.val;

	return J2;
}

//## Initialisation du plateau de jeu ##//
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

int indiceTab( int c) // on entre les coordonnees d'un point P.x ou p.y pour connaitre son indice dans le tableau.
{
if ( (c > 0) && ( c <= 60)) return 0;
if ( (c > 60) && ( c <= 70)) return 1;
if ( (c > 70) && ( c <= 130)) return 2;
if ( (c > 130) && ( c <= 140)) return 3;
if ( (c > 140) && ( c <= 200)) return 4;
if ( (c > 200) && ( c <= 210)) return 5;
if ( (c > 210) && ( c <= 270)) return 6;
if ( (c > 270) && ( c <= 280)) return 7;
if ( (c > 280) && ( c <= 340)) return 8;
if ( (c > 340) && ( c <= 350)) return 9;
if ( (c > 350) && ( c <= 410)) return 10;
if ( (c > 410) && ( c <= 420)) return 11;
if ( (c > 420) && ( c <= 480)) return 12;
if ( (c > 480) && ( c <= 490)) return 13;
if ( (c > 490) && ( c <= 550)) return 14;
if ( (c > 550) && ( c <= 560)) return 15;
if ( (c > 560) && ( c <= 620)) return 16;
return -1;
}

//## Action Joueur ##//

PLATEAU jouer_1(JOUEUR *J, PLATEAU P)
{
		POINT centre;
		int x, y; // sert pour les coordonnées
		int coup = 1; // des qu'on a jouer coup = 0 et on sort de la boucle
		
	do
	{	
		centre = wait_clic();
		x = indiceTab(centre.x); 
		y = indiceTab(centre.y);

		if ( (x%2 == 1) && (y%2 == 0) && ((P.pos[x][y+2] != 1) && (P.pos[x][y+1] != 1)) && ((*J).mur > 0) ) 
		{
			P.pos[x][y] = 1;
			P.pos[x][y+1] = 1;
			P.pos[x][y+2] = 1;
			(*J).mur -= 1;
			coup = 0;
		}
		if ( (x%2 == 0) && (y%2 == 1) && ((P.pos[x+2][y] != 1) && (P.pos[x+1][y] != 1)) && ((*J).mur > 0) ) 
		{
			P.pos[x][y] = 1;
			P.pos[x+1][y] = 1;
			P.pos[x+2][y] = 1;
			(*J).mur -= 1;
			coup = 0;
		}
		if ( ((x == (*J).i+2) && (y == (*J).j) && (P.pos[(*J).i+1][y] != 1)) || ((x == (*J).i -2) && (y == (*J).j) && (P.pos[(*J).i-1][y] != 1)) 
			|| ((y == (*J).j -2) && (x == (*J).i) && (P.pos[x][(*J).j-1] != 1)) || ((y == (*J).j +2) && (x == (*J).i) && (P.pos[x][(*J).j+1] != 1)) )
		{
			if ( (x == (*J).i+2) && (y == (*J).j) && (P.pos[x][y]  == 3) && (P.pos[x+1][y] != 1))
			{
			P.pos[x+2][y] = (*J).val;
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i += 4; (*J).j = y;
			coup = 0;
			}
			if ( (x == (*J).i-2) && (y == (*J).j) && (P.pos[x][y]  == 3) && (P.pos[x-1][y] != 1))
			{
			P.pos[x-2][y] = (*J).val;
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i -= 2; (*J).j = y;
			coup = 0;
			}
			if ( (x == (*J).i) && (y == (*J).j+2) && (P.pos[x][y]  == 3) && (P.pos[x][y+1] != 1))
			{
			P.pos[x][y+2] = (*J).val;
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i = x; (*J).j = y+2;
			coup = 0;
			}
			if ( (x == (*J).i+2) && (y == (*J).j-2) && (P.pos[x][y]  == 3) && (P.pos[x][y-1] != 1))
			{
			P.pos[x][y-2] = (*J).val;
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i = x; (*J).j = y-2;
			coup = 0;
			}
			else
			{
			P.pos[x][y] = (*J).val;
			P.pos[(*J).i][(*J).j] = 4; // case ne contenant plus de pion
			(*J).i = x; (*J).j = y;	 // on change de nouveau les valeurs de i et j du joueur
			coup = 0;
			}
		}
	}while ( coup != 0 );
	

	return P;
}

PLATEAU jouer_2(JOUEUR *J, PLATEAU P)
{
		POINT centre;
		int x, y; // sert pour les coordonnées
		int coup = 1; // des qu'on a jouer coup = 0 et on sort de la boucle
		
	do
	{	
		centre = wait_clic();
		x = indiceTab(centre.x); 
		y = indiceTab(centre.y);

		if ( (x%2 == 1) && (y%2 == 0) && ((P.pos[x][y+2] != 1) && (P.pos[x][y+1] != 1)) && ((*J).mur > 0) ) 
		{
			P.pos[x][y] = 1;
			P.pos[x][y+1] = 1;
			P.pos[x][y+2] = 1;
			(*J).mur -= 1;
			coup = 0;
		}
		if ( (x%2 == 0) && (y%2 == 1) && ((P.pos[x+2][y] != 1) && (P.pos[x+1][y] != 1)) && ((*J).mur > 0) ) 
		{
			P.pos[x][y] = 1;
			P.pos[x+1][y] = 1;
			P.pos[x+2][y] = 1;
			(*J).mur -= 1;
			coup = 0;
		}
		if ( ((x == (*J).i+2) && (y == (*J).j) && (P.pos[(*J).i+1][(*J).j] != 1)) || ((x == (*J).i -2) && (y == (*J).j) && (P.pos[(*J).i-1][(*J).j] != 1)) 
			|| ((y == (*J).j -2) && (x == (*J).i) && (P.pos[(*J).i][(*J).j-1] != 1)) || ((y == (*J).j +2) && (x == (*J).i) && (P.pos[(*J).i][(*J).j+1] != 1)) )
		{
			if ( P.pos[x][y]  == 2)
			{
			;
			}
			else
			{
			P.pos[x][y] = (*J).val;
			P.pos[(*J).i][(*J).j] = 4; // case ne contenant plus de pion
			(*J).i = x; (*J).j = y;	 // on change de nouveau les valeurs de i et j du joueur
			coup = 0;
			}
		}
	}while ( coup != 0 );
	

	return P;
}

//## Indique qui gagne ##//

int quiGagne(JOUEUR J1, JOUEUR J2)
{	
	int i;
	for ( i = 0; i < 16; i++){
		if ( P.pos[i][16] == 2) return 2;}
	for ( i = 0; i < 16; i++){
		if ( P.pos[i][0] == 3) return 3;}
	return 0;

}

//## Gestion liste doublement chainée pour les retours en arrières ##//

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


int main()
{
	init_graphics(850, 620); // initialisation de la fenetre graphique
	fill_screen(gris);
	
	int a_qui_de_jouer, i;
	JOUEUR J1, J2;

	// Debut :
	P = initPlateau();
	J1 = init_joueur1();
	J2 = init_joueur2();
	//P.pos[4][7] = 1;
	
	affichePlateau(P);
	afficheData(J1,J2);
	
	//jeu :
	a_qui_de_jouer = 1;	

	POINT p;
	p.x = 635; p.y = 370; 

for (i = 0; quiGagne(J1,J2) == 0 ; i ++ ) 
{
	
	if ( a_qui_de_jouer == 0)
	{
		aff_pol("C'est au tour de VERT", 18, p, vert);
		P = jouer_1(&J1, P);		
	}
	if ( a_qui_de_jouer == 1)
	{
		aff_pol("C'est au tour de BLEU", 18, p, bleu);
		P = jouer_2(&J2, P);
	}

	affichePlateau(P);
	afficheData(J1, J2);

	a_qui_de_jouer = 1 - a_qui_de_jouer;
	
}	

	if ( quiGagne(J1,J2) == 3) aff_pol("C'est BLEU qui GAGNE", 18, p, jaune);
	if ( quiGagne(J1,J2) == 2) aff_pol("C'est VERT qui GAGNE", 18, p, jaune);

	
	
	wait_escape();
	return 0;	
}
