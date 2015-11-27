#include <stdio.h>



int main()
{
	
	printf("P3\n");
	printf("256 256\n");
	printf("255\n \n");
	
	int i, j;
	
	for ( i = 0; i < 256; i++)
	{	
		
		for (j = 0; j < 256; j++)
		{
			
			printf("%d %d %d ",i, 0,j );
					
		}
		printf("\n");
	}
return 0;
}
