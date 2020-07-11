#include <stdio.h>

double compute(x)
{  
   return (
      (3 * x * x * x * x * x) +
      (2 * x * x * x * x)     -
      (5 * x * x * x)         -
      (x * x )                +
      (7 * x * x)             -
      6  
   );
         
}

int main(void)
{
   double x;

   printf("Enter an x value");
   scanf(" %lf", &x);


   return 0;
}