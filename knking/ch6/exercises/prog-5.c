#include <stdio.h>

int main(void)
{
   int a;
   while (1) {
      
      printf("Enter a two-digit number (negative number to exit): ");
      scanf("%d", &a);
      if (a < 0) break;
      printf("reversal of %d: ", a);
      do {
         printf("%d", a % 10);
         a /= 10;
      } while (a > 0);
      printf("\n");
   }

   return 0;
}