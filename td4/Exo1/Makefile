
## Exercice 1 ##

plim.o : plim.c
	gcc - c plim.c -o plim.o
	
plam.o : plam.c
	gcc - c plam.c -o plam.o
	
ploum.o : ploum.c plam.h plim.h
	gcc -c ploum.c -o ploum.o
	
all : plam.o plim.o ploum.o
	gcc plam.o plim.o ploum.o -o exe
	
clean :
	rm -F *.o
	rm -F exe
