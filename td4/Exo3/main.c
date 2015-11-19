
#include "simul.h"


#define LARGEUR    800
#define HAUTEUR    800



int main(){

  init_graphics(LARGEUR,HAUTEUR);
  affiche_auto_off();
  fill_screen(COUL_FOND);
  affiche_all();

  simulChaine();



  wait_escape();
  return 0;
}
