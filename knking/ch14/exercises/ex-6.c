#include <stdio.h>
#include <math.h>

double product(double x, double y) 
{
   return x * y;
}

// a)
#define DISP(f, x) printf(#f "(%g) = %g\n", (double) (x), (double) f(x))
// b)
#define DISP2(f, x, y) printf(#f "(%g, %g) = %g\n", (double) (x), (double) (y), (double) (f(x,y)))
int main(void)
{
   DISP(sqrt, 3);
   DISP2(product, 25, 55);

   return 0;
}
/**
 * Notes: without the cast, the values of the expanded 'printf' will display in the wrong order
 * In the case of DISP2, without the cast, the wrong values are displayed (in addition to displaying in the wrong order)
 */