#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"


enum direction {HAUT, BAS, DROIT, GAUCHE}; 
typedef enum direction Direction;

typedef struct plateau
{
	int pos[18][18]; // tableau de taille 18x18 ( à expliquer plus tard pourquoi)
}PLATEAU; // La case vaut 0 si il n'y a pas de mur, 1 si il y a un mur, 5 si il y n'a pas de pion  et 2 sinon.


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
	/* Initialisation de la case de départ des deux joueurs */
	P.pos[8][17] = 2; // J1
	P.pos[8][0] = 3;  // J2
	return P;
}

//## Affichage des murs ##//
void afficheMur_h()
{
	
}

void affiche_v()
{
	
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
				draw_fill_circle(p,25,rouge);
			}
			if ( P.pos[i][j] == 2) //Case ayant le pion de J1
			{
				p1.x = 70*(i/2); p1.y = 70*(j/2) ;
				p2.x = 70*(i/2) + 60; p2.y = 70*(j/2) + 60;
				draw_fill_rectangle(p1, p2, blanc);
				
				p.x = (p1.x + p2.x)/2;
				p.y = (p1.y + p2.y)/2;
				draw_fill_circle(p,25,bleu);
			}
			if ( P.pos[i][j] == 1) //case ayant un mur 
			{
				
			}
			if ( P.pos[i][j] == 0); //aucun mur (on ne fait rien)
			
						
		}
	}
}


int main()
{
	init_graphics(850, 630); // initialisation de la fenetre graphique
	fill_screen(gris);
	
	PLATEAU p;
	
	p = initPlateau();
	affichePlateau(p);
	
	
	
	
	wait_escape();
	return 0;	
}
