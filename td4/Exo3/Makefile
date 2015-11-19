#construit le fichier binaire graphics.o
graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall -lm `sdl-config --cflags`  -c graphics.c

liste.o : liste.c
	gcc -c liste.c -o liste.o

simul.o : simul.c liste.h
	gcc -c simul.c -o simul.o
	
main.o : main.c graphics.h simul.h 
	gcc -c main.c -o main.o
	
clean : 
	rm -f *.o
	rm -f exe		
	
all : graphics.o main.o simul.o liste.o
	gcc graphics.o main.o simul.o liste.o -Wall -lm `sdl-config --libs` -lSDL_ttf -o exe
	
run : all
	./exe

