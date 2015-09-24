#include "stdio.h"

int main()
{ 

	int X, Y;
	int y;
	
	X = 23; 
	Y = 87;
	y = 0;
	
	printf( " %d x %d \n", X, Y);
	
	
	while ( X > 1 ) 
	{
		
		if ( X % 2 == 0) // Pour X pair
		{
			
			Y = 2*Y;
			X = X/2;
			printf ( "= %d x %d + %d \n",X, Y, y);
			
			
			
		}
	
		else           // Pour X impair
		{
			X = (X-1);
			printf ( "= %d x %d + %d \n",X, Y, Y);
			
			y = y + Y;
			
			
		}
		
	}
	
	printf ( "= %d \n", y + Y); // y correspond au bloc apres le +, Y au bloc entre le * et le +
	
	
	
	
	
}
