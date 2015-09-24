#include "stdio.h"

int heure(int n)
{
	int h; 
	h = (n / (60*60)) % 24;
	return h;
}

int minute(int n)
{
	int m;
	m = (n /60)%60;
	return m;
	
}

int seconde(int n)
{
	int s;
	s = n %60;
	return s;
}


int main()
{ 
	int n; // L'entier rentré en seconde(s).
	
	scanf(" %d \n", &n); // Entrée au clavier du nombres de secondes.
	
	int h, m, s;
	char hp, mp, sp;
	//n = 8123;
	
	h = heure(n);
	m = minute(n);
	s = seconde(n);
	
	if ( h > 1 ) hp = 's';
	else 		 hp = ' ';
	
	if ( m > 1 ) mp = 's';
	else 		 mp = ' ';
	
	if ( s > 1 ) sp = 's';
	else 		 sp = ' ';
	
	printf(" %d secondes correspond à : %d heure%c %d minute%c %d seconde%c \n",n, h, hp, m, mp, s, sp);
	
	
	
	 

}
