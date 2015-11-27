#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************  Constantes   *****************************/
#define NbPriorite 10    //nombre total de priorités
#define Nmax       8    //nombre de requêtes générées


/**************  Définition des structures ***************/

struct requete{
  int numero;    // numéro de la requête
  int priorite;  // priorité de la requête
};
typedef struct requete Requete;



/* Définir ici la structure Fap1 et Fap2 */

struct File1{
	Requete req;
	struct File1* suiv;
};
typedef struct File1 *Fap1; 

typedef Fap1* Fap2; 


/**************  Fonctions de manipulation des structures *******/

// file initialisée vide
Fap1 initialiseFile1(){
	return NULL; 
}

// file initialisée vide
Fap2 initialiseFile2(){
 
  Fap2 f = malloc(sizeof(Fap1)*NbPriorite);
  int i;
  for ( i = 0; i< NbPriorite; i++)
  {
	f[i] = initialiseFile1();
  }
  return f;
}

void afficheFile1(Fap1 f){
  while ( f != NULL)
	{
		printf(" |%d|%d| ->",f->req.numero, f->req.priorite); // affiche : |le numero de la requete| priorité de la requete|
		f = f->suiv;
	}
	printf(" NULL \n");
	
}


void afficheFile2(Fap2 f){
 
  int i;
  for( i=0 ; i< NbPriorite ; i++)
	{
		printf(" f[%d] : ", i);
		afficheFile1(f[i]);
	} 
	printf(" \n");
}


Fap1 ajoutFile1(Fap1 f, Requete r){
  
   if ( f == NULL ) //Si f est vide on ne parcours pas la file et on ajoute r au debut;
	{
		Fap1 p = malloc(sizeof(struct File1)); 
		p->req = r;
		p->suiv = f;
		return p;
	}
	
		f->suiv = ajoutFile1(f->suiv,r);
		return f;
}



Fap2 ajoutFile2(Fap2 f, Requete r){
  int i;
  i = r.priorite;
  
  f[i] = ajoutFile1(f[i],r); // on ajout la requete r de priorité i dans le tableau f[i]
  return f;
  
}

Fap1 traiteRequete1(Fap1 f){
	
	Fap1 tmp = f; 								  // tmp est le pointeur va se balader dans ma file.
	
	if ( f == NULL ) return f; 					  // Si la file est vide on ne fait rien.
	
	int max = f->req.priorite; 					  // Va retenir la priorité la plus élevé de la file.
	
	while ( (tmp != NULL) && (tmp->suiv != NULL) )// Cherche l'élément avec la plus grande priorité.
	{
		if (max < tmp->suiv->req.priorite){
			max = tmp->suiv->req.priorite;
		}
		tmp = tmp->suiv;
	} 
	
	tmp = f; // tmp repointe le debut de la file
	
	if ( tmp->req.priorite == max) return tmp->suiv;
	while ( tmp->suiv->req.priorite != max )
	{
		tmp = tmp->suiv;
	}
	
	free(tmp->suiv);
	tmp->suiv = tmp->suiv->suiv;
	
	return f;
	
}


Fap2 traiteRequete2(Fap2 f){
    
    int i;
    for ( i = NbPriorite-1; i>= 0; i--) // on part de l'indice de plus grande priorité jusqu'à 0;
    {
		if ( f[i] != NULL) 
		{
			f[i] = traiteRequete1(f[i]);
			break;							// On fait break pour sortir de la boucle dès qu'on à fait le traitementfile1 sur f[i]
		}
		
	}
	return f;
}



void libereMemoire1(Fap1 f){
  while ( f != NULL)
	{
		free(f); 
		f = f->suiv;
	} 
}

void libereMemoire2(Fap2 f){
  int i;
  
  for ( i = 0; i < NbPriorite; i++) // On applique libèreMemoire1 sur tout les files du tableau.
  {
	libereMemoire1(f[i]);  
  }
}





/************** Génération des requêtes pour simulation *****************/

//retourne un entier aléatoire entre 0 et n-1
int alea(int n){
  return rand()%n;
}

Requete generationRequete(){
  static int numero = 0;
  Requete r;
  numero++;
  r.numero = numero;
  r.priorite = alea(NbPriorite);
  return r;
}



/************ Simulation file *****************************/


//structure 1
void simulationFile1(){
  Fap1 f1 = initialiseFile1();
  int compteur = 0;
  Requete r;
  while(compteur < Nmax){
    if(alea(2) == 0){ //traitement requête avec proba 0.5
      f1 = traiteRequete1(f1);
    }
    else{ //génération d'une nouvelle requête avec proba 0.5
      compteur++;
      r = generationRequete();
      f1 = ajoutFile1(f1, r);
    }
    afficheFile1(f1);
  }
  libereMemoire1(f1);
  printf("#######################################\n");
}


//structure 2
void simulationFile2(){
  Fap2 f2 = initialiseFile2();
  int compteur = 0;
  Requete r;
  while(compteur < Nmax){
    if(alea(2) == 0){ //traitement requête avec proba 0.5
      f2 = traiteRequete2(f2);
    }
    else{ //génération d'une nouvelle requête avec proba 0.5
      compteur++;
      r = generationRequete();
      f2 = ajoutFile2(f2, r);
    }
    afficheFile2(f2);
  }
  libereMemoire2(f2);
  printf("########################################\n");
}


/*************  Fonction main *******************************/

int main(){
  srand(time(NULL));

  /********  à décommenter pour lancer une simulation *********/
  simulationFile1();
    
  simulationFile2();

/*	Fap2 f;
	Requete r;
	r = generationRequete();
	
	f = initialiseFile2();
	f = ajoutFile2(f,r);
	r = generationRequete();
	f = ajoutFile2(f,r);
	r = generationRequete();
	f = ajoutFile2(f,r);
	r = generationRequete();
	afficheFile2(f);
	
	f = traiteRequete2(f);
	afficheFile2(f);
	*/

	
  
  return 0;
}






