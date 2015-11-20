#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"


enum direction {HAUT, BAS, DROIT, GAUCHE}; 
typedef enum direction Direction;

typedef struct plateau
{
	int pos[18][18]; 			// tableau de taille 18x18 ( à expliquer plus tard pourquoi)
}PLATEAU; 						// La case vaut 0 si il n'y a pas de mur, 1 si il y a un mur, 5 si il y n'a pas de pion  et 2 sinon.

typedef struct joueur
{
	int i,j;				    // correspond aux indices de la case du plateau;
	int val;      			    // valeur de la case du pion ( 2 pour J1, 3 pour J2)
} JOUEUR;


//## Affichage des murs ##//
void afficheMur_h(int i, int j)
{
	POINT p1, p2;
	
	p1.x = 70*((i/2)+(i%2)); p2.x = 70*(((i/2)+(i%2))+2);
	p1.y = 70*((j/2)+(j%2)); p2.y = 70*((j/2)+(j%2)) -10;
	draw_fill_rectangle(p1,p2,vert);
}

void afficheMur_v(int i, int j)
{
	POINT p1, p2;
	
	p1.x = 70*((i/2)+(i%2)); p2.x = 70*((i/2)+(i%2)) -10;
	p1.y = 70*((j/2)+(j%2)); p2.y = 70*((j/2)+(j%2) + 2);
	draw_fill_rectangle(p1,p2,vert);
}

//## Affichage du plateau de jeu ##//
void affichePlateau(PLATEAU P)
{
	int i,j;
	POINT p1, p2;
	POINT p; // centre d'un pion
	
	for ( i = 0; i < 18; i++)
	{
		for ( j = 0; j < 18; j++)
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
				draw_fill_circle(p,25,orange);
			}
			if ( P.pos[i][j] == 2) //Case ayant le pion de J1
			{
				p1.x = 70*(i/2); p1.y = 70*(j/2) ;
				p2.x = 70*(i/2) + 60; p2.y = 70*(j/2) + 60;
				draw_fill_rectangle(p1, p2, blanc);
				
				p.x = (p1.x + p2.x)/2;
				p.y = (p1.y + p2.y)/2;
				draw_fill_circle(p,25,rouge);
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

//## initialisation Joueur ##//
JOUEUR init_joueur1()
{
	JOUEUR J1;
	J1.val = 2;
	J1.i = 8;
	J1.j = 0;
	return J1;
}

JOUEUR init_joueur2()
{
	JOUEUR J2;
	J2.val = 3;
	J2.i = 8;
	J2.j = 17;
	return J2;
}

//## Initialisation du plateau de jeu ##//
PLATEAU initPlateau()
{
	int i, j;
	PLATEAU P;
	
	for ( i = 0; i < 18; i++)
	{
		for ( j = 0; j < 18; j++)
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
	init_graphics(850, 630); // initialisation de la fenetre graphique
	fill_screen(noir);
	
	PLATEAU p;
	JOUEUR J1, J2;
	int a_qui_de_jouer, i;
	
	// Debut :
	p = initPlateau();
	J1 = init_joueur1();
	J2 = init_joueur2();
	p.pos[J1.i][J1.j] = J1.val;
	p.pos[J2.i][J2.j] = J2.val;
	
	affichePlateau(p);
	
	//jeu :
	
	a_qui_de_jouer = 1;

for (i = 0; a_qui_de_jouer != -1 ; i ++ ) 
{
	
	if ( a_qui_de_jouer == 0)
	{
		
	}
	if ( a_qui_de_jouer == 1)
	{
		
	}
	
	a_qui_de_jouer = 1 - a_qui_de_jouer;
	
	}	
	
	
	
	wait_escape();
	return 0;	
}
