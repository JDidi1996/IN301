#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*

int main( int argc, char** argv) // char** argv est un tableaud e CHAINE de caractère.
{
int i;
for(i=0; i<argc; i++)
printf("%s\n", argv[i]);
return 0;
	
}
*/

/*
int main( int argc, char** argv)
{

int i;
double cmp = 0;
for ( i = 1; i < argc; i++) // On ne commence pas à 0 car on ne prend pas en compte le nom du programme.
{
	cmp += atof(argv[i]);
}	
printf(" cmp = %f\n",  cmp);
return 0;	

}
*/ 

int verifFloat(char* argv)
{ 
int i = 0;
while ( argv[i] != '\0')
{
	if ( (isdigit(argv[i])) || (argv[i] == '-') || (argv[i] == '.'))
	i++;
	else
	return 0; 
} 
	return 1;	
}

int main( int argc, char** argv)
{
	
int i; 
for ( i = 1; i < argc; i++)
{
	if ( verifFloat(argv[i]) ) printf("%s est un float\n",argv[i]);
	else 					   printf("%s n'est pas un float\n",argv[i]);
}	



return 0;	
}
