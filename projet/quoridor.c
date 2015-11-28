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
}*Liste;

Liste l;

//## Affichage des murs ##//
void afficheMur_h(int i, int j)
{
	POINT p1, p2;
	
	p1.x = 70*((i/2)+(i%2)); p2.x = 70*(((i/2)+(i%2))+1) -10;
	p1.y = 70*((j/2)+(j%2))-1; p2.y = 70*((j/2)+(j%2)) -9;
	draw_fill_rectangle(p1,p2,rouge);
}

void afficheMur_v(int i, int j)
{
	POINT p1, p2;
	
	p1.x = 70*((i/2)+(i%2))-1; p2.x = 70*((i/2)+(i%2)) -9;
	p1.y = 70*((j/2)+(j%2)); p2.y = 70*((j/2)+(j%2) + 1) -10;
	draw_fill_rectangle(p1,p2,rouge);
}

void afficheMur_c(int i, int j)
{
	POINT p1, p2;
	
	p1.x = 70*((i/2)+(i%2)); p2.x = 70*((i/2)+(i%2)) - 9;
	p1.y = 70*((j/2)+(j%2))-1; p2.y = 70*((j/2)+(j%2)) -9;
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
			if ( P.pos[i][j] == 5) //caseaccessible par un pion
			{
				p1.x = 70*(i/2); p1.y = 70*(j/2) ;
				p2.x = 70*(i/2) + 60; p2.y = 70*(j/2) + 60;
				draw_fill_rectangle(p1, p2, vert);
			}
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
				draw_fill_circle(p,25,bleumarine);
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
				if ( (i%2 == 1) && (j%2 == 1)) 
					afficheMur_c(i,j);
			}
			if ( P.pos[i][j] == 0); //aucun mur (on ne fait rien)
			
						
		}
	}
}

//## Affiche les données ##// (mur, qui doit jouer, retour en arrière)
void afficheData(JOUEUR J1, JOUEUR J2)
{
	POINT P, p1, p2;
	p1.x = 625; p1.y = 0;
	p2.x = WIDTH; p2.y = HEIGHT;
	draw_fill_rectangle(p1,p2,blanc);
	
	P.x = 640; P.y = 580;
	aff_pol("MUR Joueur bleu : ", 18, P, bleumarine);
	P.x = 810; 
	aff_int(J2.mur, 18, P, bleumarine);

	P.x = 635; P.y = 550;
	aff_pol("MUR Joueur rouge : ", 18, P,rouge);
	P.x = 815; 
	aff_int(J1.mur, 18, P, rouge);

	// Bouton retour
	
	p1.x = 660; p1.y = 150;
	p2.x = 810; p2.y = 210;
	draw_fill_rectangle(p1,p2,orange);
	draw_rectangle(p1,p2,noir);
	P.x = 690; P.y = 200;
	aff_pol("Retour", 26, P,noir);
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

//## Fonction Anti-bloquage du joueur ##//
int antiBloque(JOUEUR J, POINT P)
{
	return 0;
	
	
}

//## Gestion liste doublement chainée pour les retours en arrières ##//

Liste init_liste()
{
	return NULL;
}


Liste ajout_debut(Liste l, PLATEAU P)
{
	Liste p;
	p = malloc(sizeof(struct element));
	
	p->plt = P;
	p->suiv = l;
	
	return p;
}

int taille(Liste l)
{
	if (l == NULL) return 0;
	else return 1+ taille(l->suiv);
}

Liste supprimeDebut(Liste l, PLATEAU P)
{	
	if ( taille(l) == 1) return l;
	else 
	{
		Liste p = l->suiv;
		free(l);
		return p;	
	}
}


//## Action Joueur ##//

PLATEAU saute_pion(JOUEUR J1,JOUEUR J2, PLATEAU P)
{
	//Cas 1
		if ( (J2.i == J1.i+2) && (J1.j == J2.j) && P.pos[J1.i+3][J1.j] != 1)
		{
			P.pos[J1.i+4][J1.j] = 5;
			
		}
		if ( (J2.i == J1.i+2) && (J1.j == J2.j) && P.pos[J1.i+3][J1.j] == 1)
		{
				P.pos[J1.i+2][J1.j+2] = 5;
				P.pos[J1.i+2][J1.j-2] = 5;
		}
	//Cas 2	
		if ( (J2.i == J1.i-2) && (J1.j == J2.j) && P.pos[J1.i-3][J1.j] != 1)
		{
			P.pos[J1.i-4][J1.j] = 5;
			
		}
		if ( (J2.i == J1.i-2) && (J1.j == J2.j) && P.pos[J1.i-3][J1.j] == 1)
		{
				P.pos[J1.i-2][J1.j+2] = 5;
				P.pos[J1.i-2][J1.j-2] = 5;
		}
	//Cas 3
		if ( (J2.i == J1.i) && (J1.j+2 == J2.j) && P.pos[J1.i][J1.j+3] != 1)
		{
			P.pos[J1.i][J1.j+4] = 5;
			
		}
		if ( (J2.i == J1.i) && (J1.j+2 == J2.j) && P.pos[J1.i][J1.j+3] == 1)
		{
				P.pos[J1.i+2][J1.j+2] = 5;
				P.pos[J1.i-2][J1.j+2] = 5;
		}
	//Cas 4	
		if ( (J2.i == J1.i) && (J1.j-2 == J2.j) && P.pos[J1.i][J1.j-3] != 1)
		{
			P.pos[J1.i][J1.j-4] = 5;
			
		}
		if ( (J2.i == J1.i) && (J1.j+2 == J2.j) && P.pos[J1.i][J1.j-3] == 1)
		{
				P.pos[J1.i+2][J1.j-2] = 5;
				P.pos[J1.i-2][J1.j-2] = 5;
		}
		
	return P;
}

PLATEAU AccessJoueur ( JOUEUR J1,JOUEUR J2, PLATEAU P)
{
	P = saute_pion(J1, J2,P);
	if ( (P.pos[J1.i+1][J1.j] != 1) )
		P.pos[J1.i+2][J1.j] = 5;
	
	if ( (P.pos[J1.i-1][J1.j] != 1) )
		P.pos[J1.i+2][J1.j] = 5;

	if ( (P.pos[J1.i][J1.j+1] != 1) )
	    P.pos[J1.i][J1.j-2] = 5;

	if ( (P.pos[J1.i][J1.j-1] != 1) )
		P.pos[J1.i][J1.j+2] = 5;
	
	
	return P;
}
PLATEAU NoAccessJoueur ( JOUEUR J, PLATEAU P)
{
		P.pos[J.i+2][J.j] = 4;
		P.pos[J.i+2][J.j] = 4;
	    P.pos[J.i][J.j-2] = 4;
		P.pos[J.i][J.j+2] = 4;
	
	return P;
}

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

		// Placement de murs
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
		
		// Déplacement du pion
		if ( ((x == (*J).i+2) && (y == (*J).j) && (P.pos[(*J).i+1][y] != 1)) || ((x == (*J).i -2) && (y == (*J).j) && (P.pos[(*J).i-1][y] != 1)) 
			|| ((y == (*J).j -2) && (x == (*J).i) && (P.pos[x][(*J).j-1] != 1)) || ((y == (*J).j +2) && (x == (*J).i) && (P.pos[x][(*J).j+1] != 1)) )
		{
			if ( (x == (*J).i+2) && (y == (*J).j) && (P.pos[x][y]  == 3) && (P.pos[x+1][y] != 1))
			{
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i += 4; (*J).j = y;
			P.pos[(*J).i][(*J).j] = (*J).val; 
			coup = 0;
			}
			else if ( (x == (*J).i-2) && (y == (*J).j) && (P.pos[x][y]  == 3) && (P.pos[x-1][y] != 1))
			{
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i -= 4; (*J).j = y;
			P.pos[(*J).i][(*J).j] = (*J).val; 
			coup = 0;
			}
			else if ( (x == (*J).i) && (y == (*J).j+2) && (P.pos[x][y]  == 3) && (P.pos[x][y+1] != 1))
			{
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i = x; (*J).j += 4;
			P.pos[(*J).i][(*J).j] = (*J).val; 
			coup = 0;
			}
			else if ( (x == (*J).i) && (y == (*J).j-2) && (P.pos[x][y]  == 3) && (P.pos[x][y-1] != 1))
			{
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i = x; (*J).j -= 4;
			P.pos[(*J).i][(*J).j] = (*J).val; 
			coup = 0;
			}
			// Retour en arrière
			
			else if ( (centre.x < 810) && (centre.x > 660) && (centre.y < 210) && (centre.y > 150) )
			{
				supprimeDebut(l,l->plt);
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
			if ( (x == (*J).i+2) && (y == (*J).j) && (P.pos[x][y]  == 2) && (P.pos[x+1][y] != 1))
			{
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i += 4; (*J).j = y;
			P.pos[(*J).i][(*J).j] = (*J).val; 
			coup = 0;
			}
			else if ( (x == (*J).i-2) && (y == (*J).j) && (P.pos[x][y]  == 2) && (P.pos[x-1][y] != 1))
			{
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i -= 4; (*J).j = y;
			P.pos[(*J).i][(*J).j] = (*J).val; 
			coup = 0;
			}
			else if ( (x == (*J).i) && (y == (*J).j+2) && (P.pos[x][y]  == 2) && (P.pos[x][y+1] != 1))
			{
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i = x; (*J).j += 4;
			P.pos[(*J).i][(*J).j] = (*J).val; 
			coup = 0;
			}
			else if ( (x == (*J).i) && (y == (*J).j-2) && (P.pos[x][y]  == 2) && (P.pos[x][y-1] != 1))
			{
			P.pos[(*J).i][(*J).j] = 4; 
			(*J).i = x; (*J).j -= 4;
			P.pos[(*J).i][(*J).j] = (*J).val; 
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



int main()
{
	init_graphics(850, 620); // initialisation de la fenetre graphique
	fill_screen(gris);
	
	
	
	int a_qui_de_jouer, i;
	JOUEUR J1, J2;
		

	// Initialisation :
	P = initPlateau();
	J1 = init_joueur1();
	J2 = init_joueur2();
	l = init_liste();
	
	
	l = ajout_debut(l, P);
	affichePlateau(l->plt);
	afficheData(J1,J2);
	
	//jeu :
	POINT p;
	p.x = 630; p.y = 370; 
	a_qui_de_jouer = alea_int(2);	

for (i = 0; quiGagne(J1,J2) == 0 ; i ++ ) 
{
	if ( a_qui_de_jouer == 0)
	{
		aff_pol("C'est au tour de ROUGE", 18, p, rouge);
		
		P = jouer_1(&J1, P);
		l = ajout_debut(l, P);		
	}
	if ( a_qui_de_jouer == 1)
	{
		aff_pol("C'est au tour de BLEU", 18, p, bleu);
		P = jouer_2(&J2, P);
		l = ajout_debut(l, P);
	}

	affichePlateau(l->plt);
	afficheData(J1, J2);
	a_qui_de_jouer = 1 - a_qui_de_jouer;
	
}	

	//Annonce du gagnant
	
	if ( quiGagne(J1,J2) == 3) aff_pol("C'est BLEU qui gagne", 18, p, orange);
	if ( quiGagne(J1,J2) == 2) aff_pol("C'est ROUGE qui gagne", 18, p, orange);

	
	
	wait_escape();
	return 0;	
}
