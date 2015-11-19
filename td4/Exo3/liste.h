#define COUL_FOND  noir

typedef struct element{
  POINT p;
  struct element *suiv;
}*Liste;

// Ajout d'un element 
Liste ajoutDebut(Liste, POINT);

//Suppression d'un element
Liste supprimeDebut(Liste);

//## Affichage de la liste ##//
void dessineListeRec(Liste );

void dessineListe(Liste);
