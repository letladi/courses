#include <stdio.h>
#include <math.h>

#define CHECK(x, y, n) ((0 <= (x) && (x) <= (n - 1)) && (0 <= (y) && (y) <= (n - 1)))
#define MEDIAN(x,y,z) (((x) < (y) && (y) < (z)) ? (y) : ((y) < (x) && (x) < (z)) ? (x) : (z))
#define POLYNOMIAL(x) (3*pow(x, 5) + 2*pow(x, 4) - 5*pow(x, 3) - pow(x, 2) + 7*(x) - 6)

int main(void)
{
   printf("%lf\n", POLYNOMIAL(2));
   return 0;
}