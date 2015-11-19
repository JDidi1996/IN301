#include <stdlib.h>
#include <stdio.h>
#include "surface.h"
#include "circonference.h"
#

int main()
{
	double r;
	r = 7;
	
	printf(" surface = %f\n", surface(r));
	printf("circonference = %f\n", circonference(r*2));

}
