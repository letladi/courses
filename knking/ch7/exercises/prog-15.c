#include <stdio.h>

int main(void)
{
   printf("Enter a positive integer: ");
   int n;
   long double fact = 1;
   scanf(" %d", &n);

   while (n > 0) {
      fact *= n--;
   }

   printf("Factorial of %d: %Lf\n", n, fact);

   return 0;   
}

/*
   a) highest accurate value is 6!
   b) highest accurate value is 16!
   c) highest accurate value is 20!
   d) highest accurate value is 20!
   e) highest accurate and displayable value is 34
   f) highest displayable value is 170!
   g) highest displayable value is 1754!
*/