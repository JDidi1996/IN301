
## Exercie 2 ##

surface.o : surface.c 
	gcc -c surface.c -o surface.o
	
circonference.o : circonference.c 
	gcc -c circonference.c -o circonference.o
	
principale.o : principale.c circonference.h surface.h
	gcc -c principale.c -o principale.o
	
all : surface.o principale.o circonference.o
	gcc surface.o principale.o circonference.o -o exe
	
clean :
	rm -f *.o
	rm -f exe
