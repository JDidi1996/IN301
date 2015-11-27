#include <stdio.h>

//leafpad nomFichier &

int main(int argc, char** argv)
{
	FILE *f = fopen( argv[1], "r");
	int c = 0;
	int compt = 0;
	do
	{
		c = fgetc(f);
		compt +=1;
	}
	while(c != EOF);
	printf("%d\n",compt);
		
return 0;	
}
