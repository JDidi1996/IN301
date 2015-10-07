#include <stdio.h>

int main()
{
	double m, x, a, b, e;
	
     x = 4;
     e = 0.01;
     
    if (x > 1) 
    {
        a = 1;
        b = x;
    } 
    else 
    {
        a = x;
        b = 1;
    }
 
 
    while (b - a > e) {
        m = (a + b) / 2.;
        if (x > m * m)
            a = m;
        else
            b = m;
 
    } 
 
    printf(" racine %lf = %lf\n", x, m);
    return 0;
}
