
#construit le fichier binaire graphics.o
graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics.c

quoridor.o : quoridor.c graphics.h  
	gcc -c quoridor.c -o quoridor.o
	
all : graphics.o quoridor.o
	gcc graphics.o quoridor.o -Wall -lm `sdl-config --libs` -lSDL_ttf -o exe
	
run : all
	./exe
	
clean : 
	rm -f *.o
	rm -f exe	
