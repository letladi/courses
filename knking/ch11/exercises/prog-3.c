#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
   int old_numerator = numerator, 
   old_denominator = denominator,
   n = numerator,
   d = denominator,
   temp; 
   while (n > 0) {
      temp = n;
      n = d % n;
      d = temp;
   }
   int gcd = d;
   *reduced_numerator = old_numerator / gcd;
   *reduced_denominator = old_denominator / gcd;
}

int main(void) 
{
   int numerator, denominator, reduced_numerator, reduced_denominator;
   printf("Enter a fraction: ");
   scanf("%d / %d", &numerator, &denominator);
   reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
   printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

   return 0;
}