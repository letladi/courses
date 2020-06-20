#include <stdio.h>
#define UNSET -1

int main(void)
{
   int n = 0, i = 1;
   float error_margin;
   printf("Enter an error margin within which to approximate e: ");
   scanf("%f", &error_margin);

   
   float fact_accumulation = 1, e = 1, current_term; 
   while (1) {
      fact_accumulation *= i;
      current_term = 1.0f / fact_accumulation;
      e += current_term;
      i++;

      if (current_term < error_margin) break;
      n++;
   }

   printf("[after %d iterations] e is approximately  %.10f\n", n, e);
   return 0;
}