#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  char str[256];
 
  FILE *fic = fopen(argv[1],"r");
  
  int r,g,b,i;

  /*retire les headers */
  fgets(str, 256, fic);
  fgets(str, 256, fic);
  fgets(str, 256, fic);
  
  for(i=0; i<255; i++){
    fgets(str, 256, fic);
    r = atoi(str);
    fgets(str, 256, fic);
    g = atoi(str);
    fgets(str, 256, fic);
    b = atoi(str);
    
    r = ( r - r%4) + (argv[2][i]/64)%4;
    g = ( g - g%8) + (argv[2][i]/8)%8;
    b = ( b - b%8) + (argv[2][i])%8;
    printf("%d\n%d\n%d\n",r,g,b);
  }
  return 0;
}


