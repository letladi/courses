#include <stdio.h>

int main(void)
{
   float x;
   printf("Please enter an x value: ");
   scanf("%f", &x);

   float polyVal = ((((3 * x + 2) * x - 5 ) * x - 1) * x + 7) * x - 6;

   printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %.0f\n", polyVal);

   return 0;
}