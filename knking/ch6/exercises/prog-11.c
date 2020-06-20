#include <stdio.h>

int main(void)
{
   int n, i = 1;
   printf("Enter a number with which to approximate e: ");
   scanf("%d", &n);

   
   float fact_accumulation = 1, e = 1; 
   while (i <= n) {
      fact_accumulation *= i;
      e += 1.0f / fact_accumulation;
      i++;
   }

   printf("e is approximately %.10f\n", e);
   return 0;
}